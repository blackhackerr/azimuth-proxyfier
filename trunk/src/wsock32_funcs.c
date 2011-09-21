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

#include "wsock32_funcs.h"

#include <windows.h>

void * g_f_addr[F_COUNT];

char * g_f_name[F_COUNT] = 
{
	"accept",
	"bind",
	"closesocket",
	"connect",
	"getpeername",
	"getsockname",
	"getsockopt",
	"htonl",
	"htons",
	"inet_addr",
	"inet_ntoa",
	"ioctlsocket",
	"listen",
	"ntohl",
	"ntohs",
	"recv",
	"recvfrom",
	"select",
	"send",
	"sendto",
	"setsockopt",
	"shutdown",
	"socket",
	"MigrateWinsockConfiguration",
	"gethostbyaddr",
	"gethostbyname",
	"getprotobyname",
	"getprotobynumber",
	"getservbyname",
	"getservbyport",
	"gethostname",
	"WSAAsyncSelect",
	"WSAAsyncGetHostByAddr",
	"WSAAsyncGetHostByName",
	"WSAAsyncGetProtoByNumber",
	"WSAAsyncGetProtoByName",
	"WSAAsyncGetServByPort",
	"WSAAsyncGetServByName",
	"WSACancelAsyncRequest",
	"WSASetBlockingHook",
	"WSAUnhookBlockingHook",
	"WSAGetLastError",
	"WSASetLastError",
	"WSACancelBlockingCall",
	"WSAIsBlocking",
	"WSAStartup",
	"WSACleanup",
	"__WSAFDIsSet",
	"WEP",
	"WSApSetPostRoutine",
	"inet_network",
	"getnetbyname",
	"rcmd",
	"rexec",
	"rresvport",
	"sethostname",
	"dn_expand",
	"WSARecvEx",
	"s_perror",
	"GetAddressByNameA",
	"GetAddressByNameW",
	"EnumProtocolsA",
	"EnumProtocolsW",
	"GetTypeByNameA",
	"GetTypeByNameW",
	"GetNameByTypeA",
	"GetNameByTypeW",
	"SetServiceA",
	"SetServiceW",
	"GetServiceA",
	"GetServiceW",
	"NPLoadNameSpaces",
	"TransmitFile",
	"AcceptEx",
	"GetAcceptExSockaddrs"
};

