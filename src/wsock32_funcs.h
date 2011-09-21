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

#pragma once

#ifndef WSOCK32_FUNCS_H
#define WSOCK32_FUNCS_H

#include <windows.h>

typedef enum
{
	F_accept = 0,
	F_bind,
	F_closesocket,
	F_connect,
	F_getpeername,
	F_getsockname,
	F_getsockopt,
	F_htonl,
	F_htons,
	F_inet_addr,
	F_inet_ntoa,
	F_ioctlsocket,
	F_listen,
	F_ntohl,
	F_ntohs,
	F_recv,
	F_recvfrom,
	F_select,
	F_send,
	F_sendto,
	F_setsockopt,
	F_shutdown,
	F_socket,
	F_MigrateWinsockConfiguration,
	F_gethostbyaddr,
	F_gethostbyname,
	F_getprotobyname,
	F_getprotobynumber,
	F_getservbyname,
	F_getservbyport,
	F_gethostname,
	F_WSAAsyncSelect,
	F_WSAAsyncGetHostByAddr,
	F_WSAAsyncGetHostByName,
	F_WSAAsyncGetProtoByNumber,
	F_WSAAsyncGetProtoByName,
	F_WSAAsyncGetServByPort,
	F_WSAAsyncGetServByName,
	F_WSACancelAsyncRequest,
	F_WSASetBlockingHook,
	F_WSAUnhookBlockingHook,
	F_WSAGetLastError,
	F_WSASetLastError,
	F_WSACancelBlockingCall,
	F_WSAIsBlocking,
	F_WSAStartup,
	F_WSACleanup,
	F___WSAFDIsSet,
	F_WEP,
	F_WSApSetPostRoutine,
	F_inet_network,
	F_getnetbyname,
	F_rcmd,
	F_rexec,
	F_rresvport,
	F_sethostname,
	F_dn_expand,
	F_WSARecvEx,
	F_s_perror,
	F_GetAddressByNameA,
	F_GetAddressByNameW,
	F_EnumProtocolsA,
	F_EnumProtocolsW,
	F_GetTypeByNameA,
	F_GetTypeByNameW,
	F_GetNameByTypeA,
	F_GetNameByTypeW,
	F_SetServiceA,
	F_SetServiceW,
	F_GetServiceA,
	F_GetServiceW,
	F_NPLoadNameSpaces,
	F_TransmitFile,
	F_AcceptEx,
	F_GetAcceptExSockaddrs,

	F_COUNT
} F_ENUM;

extern void * g_f_addr[F_COUNT];
extern char * g_f_name[F_COUNT];

#endif // WSOCK32_FUNCS_H
