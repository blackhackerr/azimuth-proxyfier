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

#include "ws2_32_funcs.h"

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
	"ioctlsocket",
	"inet_addr",
	"inet_ntoa",
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
	"GetAddrInfoW",
	"GetNameInfoW",
	"WSApSetPostRoutine",
	"FreeAddrInfoW",
	"WPUCompleteOverlappedRequest",
	"WSAAccept",
	"WSAAddressToStringA",
	"WSAAddressToStringW",
	"WSACloseEvent",
	"WSAConnect",
	"WSACreateEvent",
	"WSADuplicateSocketA",
	"WSADuplicateSocketW",
	"WSAEnumNameSpaceProvidersA",
	"WSAEnumNameSpaceProvidersW",
	"WSAEnumNetworkEvents",
	"WSAEnumProtocolsA",
	"WSAEnumProtocolsW",
	"WSAEventSelect",
	"WSAGetOverlappedResult",
	"WSAGetQOSByName",
	"WSAGetServiceClassInfoA",
	"WSAGetServiceClassInfoW",
	"WSAGetServiceClassNameByClassIdA",
	"WSAGetServiceClassNameByClassIdW",
	"WSAHtonl",
	"WSAHtons",
	"gethostbyaddr",
	"gethostbyname",
	"getprotobyname",
	"getprotobynumber",
	"getservbyname",
	"getservbyport",
	"gethostname",
	"WSAInstallServiceClassA",
	"WSAInstallServiceClassW",
	"WSAIoctl",
	"WSAJoinLeaf",
	"WSALookupServiceBeginA",
	"WSALookupServiceBeginW",
	"WSALookupServiceEnd",
	"WSALookupServiceNextA",
	"WSALookupServiceNextW",
	"WSANSPIoctl",
	"WSANtohl",
	"WSANtohs",
	"WSAProviderConfigChange",
	"WSARecv",
	"WSARecvDisconnect",
	"WSARecvFrom",
	"WSARemoveServiceClass",
	"WSAResetEvent",
	"WSASend",
	"WSASendDisconnect",
	"WSASendTo",
	"WSASetEvent",
	"WSASetServiceA",
	"WSASetServiceW",
	"WSASocketA",
	"WSASocketW",
	"WSAStringToAddressA",
	"WSAStringToAddressW",
	"WSAWaitForMultipleEvents",
	"WSCDeinstallProvider",
	"WSCEnableNSProvider",
	"WSCEnumProtocols",
	"WSCGetProviderPath",
	"WSCInstallNameSpace",
	"WSCInstallProvider",
	"WSCUnInstallNameSpace",
	"WSCUpdateProvider",
	"WSCWriteNameSpaceOrder",
	"WSCWriteProviderOrder",
	"freeaddrinfo",
	"getaddrinfo",
	"getnameinfo",
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
	"WEP"
};

