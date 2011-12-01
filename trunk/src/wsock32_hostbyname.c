/*
 * Copyright (C) 2011, Pavel Samko <bulldozerbsg@gmail.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the "Pavel Samko" nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#ifdef WS2
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#include "wsock32_hostbyname.h"
#ifdef WS2
#include "ws2_32_stubs.h"
#else
#include "wsock32_stubs.h"
#endif
#include "wsock32_config.h"
#include <stdlib.h>
#include <stdio.h>

#define NO_IP 0

typedef struct HBN_NODE HBN_NODE;
struct HBN_NODE
{
	HOSTENT * m_hostent;
	char * m_host_ip;
	HBN_NODE * m_next;
};

typedef struct HBN
{
	CRITICAL_SECTION m_mutex;
	HBN_NODE * m_node;
} HBN;

HBN * g_hbn = NULL;

HOSTENT * _hbn_newhostent(const char * a, u_long ip)
{
	HOSTENT * result = NULL;
	if (a)
	{
		result = (HOSTENT *)malloc(sizeof(HOSTENT));
		memset(result, 0, sizeof(HOSTENT));
		// name
		size_t name_len = strlen(a);
		result->h_name = (char *)malloc(name_len + 1);
		memset(result->h_name, 0, name_len + 1);
		strcpy(result->h_name, a);
		// aliases
		static char * _aliases[1] = {NULL};
		result->h_aliases = _aliases;
		// addrtype
		result->h_addrtype = AF_INET;
		// length
		result->h_length = sizeof(u_long);
		// addr_list
		result->h_addr_list = (char **)malloc(sizeof(char *) * 2);
		result->h_addr_list[0] = (char *)malloc(sizeof(u_long));
		result->h_addr_list[1] = NULL;
		if (ip != NO_IP)
		{
			memcpy(result->h_addr_list[0], &ip, sizeof(u_long));
		} else
		{
			memcpy(result->h_addr_list[0], &result, sizeof(u_long)); // :)
		}
	}
	return result;
}

void _hbn_deletehostent(HOSTENT * a)
{
	if (a)
	{
		// addr_list
		if (a->h_addr_list)
		{
			if (a->h_addr_list[0])
			{
				free(a->h_addr_list[0]);
				a->h_addr_list[0] = NULL;
			}
			free(a->h_addr_list);
		}
		// name
		if (a->h_name)
		{
			free(a->h_name);
		}
		memset(a, 0, sizeof(HOSTENT));
		free(a);
	}
}

void hbn_init(void)
{
	if (!g_hbn)
	{
		g_hbn = (HBN *)malloc(sizeof(HBN));
		memset(g_hbn, 0, sizeof(HBN));
		InitializeCriticalSection(&g_hbn->m_mutex);
		g_hbn->m_node = NULL;
		if (g_proxy_usehosts)
		{
			EnterCriticalSection(&g_hbn->m_mutex);
			FILE * f = fopen(g_hosts_path, "r");
			if (f)
			{
				static char line[1024];
				while (fgets(line, 1024, f))
				{
					// strip comment
					char * grid = strchr(line, '#');
					if (grid)
					{
						grid[0] = '\0';
					}
					// convert to hostent
					u_long ip = NO_IP;
					char * ip_s = NULL;
					char * host_s = NULL;
					char * pch = strtok(line, " \t\n\r");
					while (pch)
					{
						if (!ip_s)
						{
							ip_s = pch;
							ip = stub_inet_addr(ip_s);
						} else
						{
							host_s = pch;
							// create new record
							HBN_NODE * node = (HBN_NODE *)malloc(sizeof(HBN_NODE));
							memset(node, 0, sizeof(HBN_NODE));
							node->m_hostent = _hbn_newhostent(host_s, ip);
							node->m_host_ip = (char *)malloc(strlen(ip_s) + 1);
							strcpy(node->m_host_ip, ip_s);
							node->m_next = g_hbn->m_node;
							g_hbn->m_node = node;
						}
						pch = strtok(NULL, " \t\n\r");
					}
				}
				fclose(f);
			}
			LeaveCriticalSection(&g_hbn->m_mutex);
		}
	}
}

void hbn_deinit(void)
{
	if (g_hbn)
	{
		if (g_hbn->m_node)
		{
			HBN_NODE * node = g_hbn->m_node;
			while (node)
			{
				g_hbn->m_node = node->m_next;
				_hbn_deletehostent(node->m_hostent);
				if (node->m_host_ip)
				{
					free(node->m_host_ip);
				}
				free(node);
				node = g_hbn->m_node;
			}
		}
		DeleteCriticalSection(&g_hbn->m_mutex);
		free(g_hbn);
		g_hbn = NULL;
	}
}

PHOSTENT hbn_gethostbyname(const char * a)
{
	PHOSTENT result = NULL;
	if (a && g_hbn)
	{
		EnterCriticalSection(&g_hbn->m_mutex);
		// find exist record
		HBN_NODE * find_node = g_hbn->m_node;
		while (find_node)
		{
			if (find_node->m_hostent && find_node->m_hostent->h_name && !_stricmp(find_node->m_hostent->h_name, a))
			{
				break;
			}
			find_node = find_node->m_next;
		}
		if (find_node)
		{
			// found
			result = find_node->m_hostent;
		} else
		{
			// not found. create new record
			HBN_NODE * node = (HBN_NODE *)malloc(sizeof(HBN_NODE));
			memset(node, 0, sizeof(HBN_NODE));
			node->m_hostent = _hbn_newhostent(a, NO_IP);
			node->m_next = g_hbn->m_node;
			g_hbn->m_node = node;
			result = node->m_hostent;
		}
		LeaveCriticalSection(&g_hbn->m_mutex);
	}
	return result;
}

char * hbn_getnamebyaddr(u_long a)
{
	char * result = NULL;
	if (g_hbn)
	{
		EnterCriticalSection(&g_hbn->m_mutex);
		// find exist record
		HBN_NODE * find_node = g_hbn->m_node;
		while (find_node)
		{
			if (find_node->m_hostent && find_node->m_hostent->h_addr_list && find_node->m_hostent->h_addr_list[0] && !memcmp(&a, find_node->m_hostent->h_addr_list[0], sizeof(u_long)))
			{
				break;
			}
			find_node = find_node->m_next;
		}
		if (find_node)
		{
			if (find_node->m_host_ip)
			{
				result = find_node->m_host_ip;
			} else
			if (find_node->m_hostent && find_node->m_hostent->h_name)
			{
				result = find_node->m_hostent->h_name;
			}
		}
		LeaveCriticalSection(&g_hbn->m_mutex);
	}
	return result;
}
