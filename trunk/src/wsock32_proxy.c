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

#include <windows.h>
#ifdef WS2
#include <winsock2.h>
#else
#include <winsock.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "wsock32_base64.h"
#ifdef WS2
#include "ws2_32_funcs.h"
#else
#include "wsock32_funcs.h"
#endif
#include "wsock32_hostbyname.h"
#ifdef WS2
#include "ws2_32_stubs.h"
#else
#include "wsock32_stubs.h"
#endif
#include "wsock32_fifobuff.h"
#include "wsock32_httpparser.h"
#include "wsock32_config.h"
#include <ntlm.h> // libntlm-0.dll

int p_send(SOCKET s, void * data, size_t data_size)
{
	if ((s != INVALID_SOCKET) && data && data_size)
	{
		char * send_data = (char *)data;
		int r = 0;
		while (data_size > 0)
		{
			r = stub_send(s, send_data, data_size, 0);
			if (r < 0)
			{
				int err = stub_WSAGetLastError();
				if (err == WSAEWOULDBLOCK)
				{
					r = 0;
					continue;
				} else
				{
					return 0;
				}
			} else
			if (r == 0)
			{
				return 0;
			}
			send_data += r;
			data_size -= r;
		}
		return 1;
	}
	return 0;
}

int p_recv(SOCKET s, void * data, size_t data_size)
{
	if ((s != INVALID_SOCKET) && data && data_size)
	{
		char * recv_data = (char *)data;
		int r = 0;
		while (data_size > 0)
		{
			r = stub_recv(s, recv_data, data_size, 0);
			if (r < 0)
			{
				int err = stub_WSAGetLastError();
				if (err == WSAEWOULDBLOCK)
				{
					r = 0;
					continue;
				} else
				{
					return 0;
				}
			} else
			if (r == 0)
			{
				return 0;
			}
			recv_data += r;
			data_size -= r;
		}
		return 1;
	}
	return 0;
}

// IN & OUT (null terminated, base64)
char * p_getntlm(char * challenge)
{
	char * ntlm_enc = NULL;
	//if (g_proxy_user && g_proxy_pass)
	{
		if (!challenge)
		{
			// Request
			tSmbNtlmAuthRequest ntlm;
			buildSmbNtlmAuthRequest(&ntlm, g_proxy_user, NULL);
			size_t ntlm_size = SmbLength(&ntlm);
			size_t ntlm_enc_size = base64_enc_size((char *)&ntlm, ntlm_size);
			ntlm_enc = (char *)malloc(ntlm_enc_size + 1);
			memset(ntlm_enc, 0, ntlm_enc_size + 1);
			base64_enc((char *)&ntlm, ntlm_size, ntlm_enc, ntlm_enc_size);
		} else
		{
			// Response
			size_t challenge_size = strlen(challenge);
			size_t challenge_dec_size = base64_dec_size(challenge, challenge_size);
			tSmbNtlmAuthChallenge challenge_dec;
			memset(&challenge_dec, 0, sizeof(tSmbNtlmAuthChallenge));
			base64_dec(challenge, challenge_size, (char *)&challenge_dec, challenge_dec_size);
			tSmbNtlmAuthResponse ntlm;
			buildSmbNtlmAuthResponse(&challenge_dec, &ntlm, g_proxy_user, g_proxy_pass);
			size_t ntlm_size = SmbLength(&ntlm);
			size_t ntlm_enc_size = base64_enc_size((char *)&ntlm, ntlm_size);
			ntlm_enc = (char *)malloc(ntlm_enc_size + 1);
			memset(ntlm_enc, 0, ntlm_enc_size + 1);
			base64_enc((char *)&ntlm, ntlm_size, ntlm_enc, ntlm_enc_size);
		}
	}
	return ntlm_enc;
}

// OUT (null terminated, base64)
char * p_getbasic(void)
{
	char * basic_enc = NULL;
	//if (g_proxy_user && g_proxy_pass)
	{
		size_t basic_size = strlen(g_proxy_user) + strlen(g_proxy_pass) + 1;
		char * basic = (char *)malloc(basic_size + 1);
		memset(basic, 0, basic_size + 1);
		sprintf(basic, "%s:%s", g_proxy_user, g_proxy_pass);
		size_t basic_enc_size = base64_enc_size(basic, basic_size);
		basic_enc = (char *)malloc(basic_enc_size + 1);
		memset(basic_enc, 0, basic_enc_size + 1);
		base64_enc(basic, basic_size, basic_enc, basic_enc_size);
		free(basic);
	}
	return basic_enc;
}

int p_sendquery(SOCKET s, HTTP_ANSWER_CODE answer_code, HTTP_ANSWER ** answer, char * name, u_short port)
{
	if ((s != INVALID_SOCKET) && answer && name && port)
	{
		switch (answer_code)
		{
			case HTTP_NONE:
				{
					char query[512] = {0};
					if (!g_proxy_useauth)
					{
						sprintf(query, \
							"CONNECT %s:%hu HTTP/1.1\r\n" \
							"Connection: Keep-alive\r\n" \
							"Host: %s:%hu\r\n" \
							"\r\n", \
							name, stub_ntohs(port), \
							name, stub_ntohs(port));
					} else
					{
						if (g_proxy_usentlm)
						{
							char * ntlm = p_getntlm(NULL);
							if (ntlm)
							{
								sprintf(query, \
									"CONNECT %s:%hu HTTP/1.1\r\n" \
									"Connection: Keep-alive\r\n" \
									"Host: %s:%hu\r\n" \
									"Proxy-Authorization: NTLM %s\r\n" \
									"\r\n", \
									name, stub_ntohs(port), \
									name, stub_ntohs(port), \
									ntlm);
								free(ntlm);
							} else
							{
								break;
							}
						} else
						{
							char * basic = p_getbasic();
							if (basic)
							{
								sprintf(query, \
									"CONNECT %s:%hu HTTP/1.1\r\n" \
									"Connection: Keep-alive\r\n" \
									"Host: %s:%hu\r\n" \
									"Proxy-Authorization: Basic %s\r\n" \
									"\r\n", \
									name, stub_ntohs(port), \
									name, stub_ntohs(port), \
									basic);
								free(basic);
							} else
							{
								break;
							}
						}
					}
					return p_send(s, query, strlen(query));
				}
				break;
			case HTTP_PROXY_AUTHENTICATION_REQUIRED:
				{
					char query[512] = {0};
					if (g_proxy_useauth && g_proxy_usentlm && *answer)
					{
						char * ntlm = hp_answer_getvalueforkey(*answer, "Proxy-Authenticate");
						char * ntlm_key = NULL;
						char * ntlm_val = NULL;
						if (ntlm && (strlen(ntlm) > 4))
						{
							char * token = strtok(ntlm, " ");
							while (token)
							{
								if (!ntlm_key)
								{
									ntlm_key = token;
								} else
								if (!ntlm_val)
								{
									ntlm_val = token;
									break;
								}
								token = strtok(NULL, " ");
							}
						}
						if (ntlm_val)
						{
							char * ntlm = p_getntlm(ntlm_val);
							if (ntlm)
							{
								sprintf(query, \
									"CONNECT %s:%hu HTTP/1.1\r\n" \
									"Connection: Keep-alive\r\n" \
									"Host: %s:%hu\r\n" \
									"Proxy-Authorization: NTLM %s\r\n" \
									"\r\n", \
									name, stub_ntohs(port), \
									name, stub_ntohs(port), \
									ntlm);
								free(ntlm);
							} else
							{
								break;
							}
							return p_send(s, query, strlen(query));
						}
					}
				}
				break;
			default:
				break;
		}
	}
	return 0;
}

int p_recvanswer(SOCKET s, HTTP_ANSWER_CODE * answer_code, HTTP_ANSWER ** answer)
{
	if ((s != INVALID_SOCKET) && answer_code && answer)
	{
		// delete prev_answer
		if (*answer)
		{
			hp_answer_delete(*answer);
			*answer = NULL;
			*answer_code = HTTP_INVALID;
		}
		// read answer from socket
		int all_data = 0;
		FIFOBUFF * rbuff = fb_new(0);
		while (rbuff && !all_data)
		{
			fb_pushzero(rbuff, 1);
			if (!p_recv(s, (char *)fb_getdataptr(rbuff) + fb_size(rbuff) - 1, 1))
			{
				break;
			}
			if ((fb_size(rbuff) >= 4) && (!memcmp(((char *)fb_getdataptr(rbuff)) + fb_size(rbuff) - 4, "\r\n\r\n", 4)))
			{
				fb_pushzero(rbuff, 1);
				all_data = 1;
			}
		}
		// parse answer from buff
		if (rbuff && all_data)
		{
			*answer = hp_answer_parse((char *)fb_getdataptr(rbuff));
			if (*answer)
			{
				*answer_code = hp_answer_getcode(*answer);
			}
		}
		fb_delete(rbuff);
		if (*answer_code != HTTP_INVALID)
		{
			return 1;
		}
	}
	return 0;
}

int p_connecttoproxy(SOCKET s, char * name, u_long ip, u_short port)
{
	// if name != NULL dont use ip
	/*char name_ip[16] = {0};
	if (!name)
	{
		IN_ADDR addr_ip;
		addr_ip.S_un.S_addr = ip;
		sprintf(name_ip, "%hhu.%hhu.%hhu.%hhu", addr_ip.S_un.S_un_b.s_b1, addr_ip.S_un.S_un_b.s_b2, addr_ip.S_un.S_un_b.s_b3, addr_ip.S_un.S_un_b.s_b4);
		name = name_ip;
	}*/
	if ((s != INVALID_SOCKET) && name)
	{
		SOCKADDR_IN addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_addr.S_un.S_addr = stub_inet_addr(g_proxy_addr);
		addr.sin_family = AF_INET;
		addr.sin_port = stub_htons(g_proxy_port);
		int r = stub_connect(s, (SOCKADDR *)&addr, sizeof(addr));
		while (r)
		{
			int err = stub_WSAGetLastError();
			if ((err == WSAEWOULDBLOCK) || (err == WSAEALREADY) || (err == WSAEINVAL)) // non blocked socket
			{
				r = stub_connect(s, (SOCKADDR *)&addr, sizeof(addr));
				continue;
			} else
			if (err == WSAEISCONN)
			{
				r = 0;
			}
			break;
		}
		if (!r)
		{
			// Connected or inprogress
			int connected = 0;
			HTTP_ANSWER_CODE answer_code = HTTP_NONE;
			HTTP_ANSWER * answer = NULL;
			while (!connected)
			{
				// Q
				if (!p_sendquery(s, answer_code, &answer, name, port))
				{
					break; // error
				}
				// A
				if (!p_recvanswer(s, &answer_code, &answer))
				{
					break; // error
				}
				// check code
				if (hp_answer_iscode_success(answer_code))
				{
					connected = 1;
					break;
				} else
				if (hp_answer_iscode_cerror(answer_code))
				{
					if (answer_code == HTTP_PROXY_AUTHENTICATION_REQUIRED)
					{
						char * ntlm_s = hp_answer_getvalueforkey(answer, "Proxy-Authenticate");
						if (ntlm_s && (strlen(ntlm_s) > 4))
						{
							// need recive http data
							char * conlen_s = hp_answer_getvalueforkey(answer, "Content-Length");
							if (conlen_s)
							{
								size_t conlen = (size_t)atoi(conlen_s);
								FIFOBUFF * rbuff = fb_new(conlen);
								fb_pushzero(rbuff, conlen);
								if (!p_recv(s, (char *)fb_getdataptr(rbuff), conlen))
								{
									break;
								}
								fb_delete(rbuff);
							}
							continue;
						}
						break;
					}
				} else
				if (hp_answer_iscode_serror(answer_code))
				{
					break;
				}
			}
			hp_answer_delete(answer);
			return connected;
		}
	}
	return 0;
}

// Proxy stabs

PHOSTENT PASCAL proxy_gethostbyname(const char * a)
{
	if (g_proxy_use)
	{
		PHOSTENT result = hbn_gethostbyname(a);
		if (!result)
		{
			stub_WSASetLastError(WSAHOST_NOT_FOUND);
		} else
		{
			stub_WSASetLastError(0);
		}
		return result;
	}
	return stub_gethostbyname(a);
}

int PASCAL proxy_connect(unsigned int a, const SOCKADDR * b, int c)
{
	if (g_proxy_use)
	{
		if ((a != INVALID_SOCKET) && b && (c == sizeof(SOCKADDR_IN)))
		{
			SOCKADDR_IN * addr = (SOCKADDR_IN *)b;
			if (addr->sin_family == AF_INET) // support IP4
			{
				u_long addr_ip = addr->sin_addr.S_un.S_addr;
				u_short addr_port = addr->sin_port;
				char * addr_name = hbn_getnamebyaddr(addr_ip);
				if (!addr_name)
				{
					addr_name = stub_inet_ntoa(addr->sin_addr);
				}
				// process connect to proxy
				if (p_connecttoproxy((SOCKET)a, addr_name, addr_ip, addr_port))
				{
					stub_WSASetLastError(0);
					return 0;
				} else
				{
					stub_WSASetLastError(WSAENETUNREACH);
					return SOCKET_ERROR;
				}
			}
		}
	}
	return stub_connect(a, b, c);
}
