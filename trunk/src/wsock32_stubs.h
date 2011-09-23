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

#ifndef WSOCK32_STUBS_H
#define WSOCK32_STUBS_H

#include <windows.h>
#include <winsock.h>

unsigned int PASCAL stub_accept(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_bind(unsigned int a, const SOCKADDR * b, int c);
int PASCAL stub_closesocket(unsigned int a);
int PASCAL stub_connect(unsigned int a, const SOCKADDR * b, int c);
int PASCAL stub_getpeername(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_getsockname(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_getsockopt(unsigned int a, int b, int c, char * d, int * e);
unsigned long int PASCAL stub_htonl(unsigned long int a);
unsigned short int PASCAL stub_htons(unsigned short int a);
unsigned long int PASCAL stub_inet_addr(const char * a);
char * PASCAL stub_inet_ntoa(IN_ADDR a);
int PASCAL stub_ioctlsocket(unsigned int a, long int b, unsigned long int * c);
int PASCAL stub_listen(unsigned int a, int b);
unsigned long int PASCAL stub_ntohl(unsigned long int a);
unsigned short int PASCAL stub_ntohs(unsigned short int a);
int PASCAL stub_recv(unsigned int a, char * b, int c, int d);
int PASCAL stub_recvfrom(unsigned int a, char * b, int c, int d, PSOCKADDR e, int * g);
int PASCAL stub_select(int a, PFD_SET b, PFD_SET c, PFD_SET d, const TIMEVAL * e);
int PASCAL stub_send(unsigned int a , const char * b, int c, int d);
int PASCAL stub_sendto(unsigned int a, const char * b, int c, int d, const SOCKADDR * e, int g);
int PASCAL stub_setsockopt(unsigned int a, int b, int c, const char * d, int e);
int PASCAL stub_shutdown(unsigned int a, int b);
unsigned int PASCAL stub_socket(int a, int b, int c);
INT PASCAL stub_MigrateWinsockConfiguration(DWORD a, DWORD b, DWORD c);
PHOSTENT PASCAL stub_gethostbyaddr(const char * a, int b, int c);
PHOSTENT PASCAL stub_gethostbyname(const char * a);
PPROTOENT PASCAL stub_getprotobyname(const char * a);
PPROTOENT PASCAL stub_getprotobynumber(int a);
PSERVENT PASCAL stub_getservbyname(const char * a, const char * b);
PSERVENT PASCAL stub_getservbyport(int a, const char * b);
int PASCAL stub_gethostname(char * a, int b);
int PASCAL stub_WSAAsyncSelect(unsigned int a, HWND b, unsigned int c, long int d);
void * PASCAL stub_WSAAsyncGetHostByAddr(HWND a, unsigned int b, const char * c, int d, int e, char * g, int h);
void * PASCAL stub_WSAAsyncGetHostByName(HWND a, unsigned int b, const char * c, char * d, int e);
void * PASCAL stub_WSAAsyncGetProtoByNumber(HWND a, unsigned int b, int c, char * d, int e);
void * PASCAL stub_WSAAsyncGetProtoByName(HWND a, unsigned int b, const char * c, char * d, int e);
void * PASCAL stub_WSAAsyncGetServByPort(HWND a, unsigned int b, int c, const char * d, char * e, int g);
void * PASCAL stub_WSAAsyncGetServByName(HWND a, unsigned int b, const char * c, const char * d, char * e, int g);
int PASCAL stub_WSACancelAsyncRequest(void * a);
void * PASCAL stub_WSASetBlockingHook(void * a);
int PASCAL stub_WSAUnhookBlockingHook(void);
int PASCAL stub_WSAGetLastError(void);
void PASCAL stub_WSASetLastError(int a);
int PASCAL stub_WSACancelBlockingCall(void);
int PASCAL stub_WSAIsBlocking(void);
int PASCAL stub_WSAStartup(unsigned short int a, LPWSADATA b);
int PASCAL stub_WSACleanup(void);
int PASCAL stub___WSAFDIsSet(unsigned int a, PFD_SET b);
BOOL PASCAL stub_WEP(DWORD a);
BOOL PASCAL stub_WSApSetPostRoutine(PVOID a);
UINT PASCAL stub_inet_network(const char * a);
void */*substitution type (struct netent*)*/ PASCAL stub_getnetbyname(const char * a);
SOCKET PASCAL stub_rcmd(char ** a, USHORT b, char *	c, char * d, char * e, int * g);
SOCKET PASCAL stub_rexec(char ** a, USHORT b, char *	c, char * d, char * e, int * g);
SOCKET PASCAL stub_rresvport(int * a);
int PASCAL stub_sethostname(char * a, int b);
int PASCAL stub_dn_expand(unsigned char * a, unsigned char * b, unsigned char * c, unsigned char * d, int e);
int PASCAL stub_WSARecvEx(unsigned int a, char * b, int c, int * d);
void PASCAL stub_s_perror(const char * a);
INT PASCAL stub_GetAddressByNameA(DWORD a, LPGUID b, LPSTR c, LPINT d, DWORD e, void * g/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPVOID h, LPDWORD i, LPSTR j, LPDWORD k);
INT PASCAL stub_GetAddressByNameW(DWORD a, LPGUID b, LPWSTR c, LPINT d, DWORD e, void * g/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPVOID h, LPDWORD i, LPWSTR j, LPDWORD k);
INT PASCAL stub_EnumProtocolsA(LPINT a, LPVOID b, LPDWORD c);
INT PASCAL stub_EnumProtocolsW(LPINT a, LPVOID b, LPDWORD c);
INT PASCAL stub_GetTypeByNameA(LPSTR a, LPGUID b);
INT PASCAL stub_GetTypeByNameW(LPWSTR a, LPGUID b);
INT PASCAL stub_GetNameByTypeA(LPGUID a, LPSTR b, DWORD c);
INT PASCAL stub_GetNameByTypeW(LPGUID a, LPWSTR b, DWORD c);
INT PASCAL stub_SetServiceA(DWORD a, DWORD b, DWORD c, void * d/*substitution type (LPSERVICE_INFOA)*/, void * e/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPDWORD g);
INT PASCAL stub_SetServiceW(DWORD a, DWORD b, DWORD c, void * d/*substitution type (LPSERVICE_INFOW)*/, void * e/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPDWORD g);
INT PASCAL stub_GetServiceA(DWORD a, LPGUID b, LPSTR c, DWORD d, LPVOID e, LPDWORD g, void * h/*substitution type (LPSERVICE_ASYNC_INFO)*/);
INT PASCAL stub_GetServiceW(DWORD a, LPGUID b, LPWSTR c, DWORD d, LPVOID e, LPDWORD g, void * h/*substitution type (LPSERVICE_ASYNC_INFO)*/);
INT PASCAL stub_NPLoadNameSpaces(LPDWORD a, void */*substitution type (LPNS_ROUTINE)*/ b, LPDWORD c);
BOOL PASCAL stub_TransmitFile(SOCKET a, HANDLE b, DWORD c, DWORD d, LPOVERLAPPED e, LPTRANSMIT_FILE_BUFFERS g, DWORD h);
BOOL PASCAL stub_AcceptEx(SOCKET a, SOCKET b, PVOID c, DWORD d, DWORD e, DWORD g, LPDWORD h, LPOVERLAPPED i);
VOID PASCAL stub_GetAcceptExSockaddrs(PVOID a, DWORD b, DWORD c, DWORD d, PSOCKADDR * e, LPINT g, PSOCKADDR * h, LPINT i);

#endif // WSOCK32_STUBS_H
