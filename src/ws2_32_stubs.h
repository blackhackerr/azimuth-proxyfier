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

#ifndef WS2_32_STUBS_H
#define WS2_32_STUBS_H

#include <windows.h>
#include <winsock2.h>

unsigned int PASCAL stub_accept(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_bind(unsigned int a, const SOCKADDR * b, int c);
int PASCAL stub_closesocket(unsigned int a);
int PASCAL stub_connect(unsigned int a, const SOCKADDR * b, int c);
int PASCAL stub_getpeername(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_getsockname(unsigned int a, PSOCKADDR b, int * c);
int PASCAL stub_getsockopt(unsigned int a, int b, int c, char * d, int * e);
unsigned long int PASCAL stub_htonl(unsigned long int a);
unsigned short int PASCAL stub_htons(unsigned short int a);
int PASCAL stub_ioctlsocket(unsigned int a, long int b, unsigned long int * c);
unsigned long int PASCAL stub_inet_addr(const char * a);
char * PASCAL stub_inet_ntoa(IN_ADDR a);
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
INT PASCAL stub_GetAddrInfoW(PCWSTR a, PCWSTR b, const /*ADDRINFOW*/void * c, /*PADDRINFOW*/void * d);
INT PASCAL stub_GetNameInfoW(const SOCKADDR * a, /*socklen_t*/int b, PWCHAR c, DWORD d, PWCHAR e, DWORD g, INT h);
BOOL PASCAL stub_WSApSetPostRoutine(PVOID a);
VOID PASCAL stub_FreeAddrInfoW(PVOID a);
int PASCAL stub_WPUCompleteOverlappedRequest(SOCKET a, LPWSAOVERLAPPED b, DWORD c, DWORD d, LPINT e);
SOCKET PASCAL stub_WSAAccept(SOCKET a, struct sockaddr* b, LPINT c, LPCONDITIONPROC d, DWORD_PTR e);
INT PASCAL stub_WSAAddressToStringA(LPSOCKADDR a, DWORD b, LPWSAPROTOCOL_INFOA c, LPSTR d, LPDWORD e);
INT PASCAL stub_WSAAddressToStringW(LPSOCKADDR a, DWORD b, LPWSAPROTOCOL_INFOW c, LPWSTR d, LPDWORD e);
BOOL PASCAL stub_WSACloseEvent(WSAEVENT a);
int PASCAL stub_WSAConnect(SOCKET a, const struct sockaddr* b, int c, LPWSABUF d, LPWSABUF e, LPQOS g, LPQOS h);
WSAEVENT PASCAL stub_WSACreateEvent(void);
int PASCAL stub_WSADuplicateSocketA(SOCKET a, DWORD b, LPWSAPROTOCOL_INFOA c);
int PASCAL stub_WSADuplicateSocketW(SOCKET a, DWORD b, LPWSAPROTOCOL_INFOW c);
INT PASCAL stub_WSAEnumNameSpaceProvidersA(LPDWORD a, LPWSANAMESPACE_INFOA b);
INT PASCAL stub_WSAEnumNameSpaceProvidersW(LPDWORD a, LPWSANAMESPACE_INFOW b);
int PASCAL stub_WSAEnumNetworkEvents(SOCKET a, WSAEVENT b, LPWSANETWORKEVENTS c);
int PASCAL stub_WSAEnumProtocolsA(LPINT a, LPWSAPROTOCOL_INFOA b, LPDWORD c);
int PASCAL stub_WSAEnumProtocolsW(LPINT a, LPWSAPROTOCOL_INFOW b, LPDWORD c);
int PASCAL stub_WSAEventSelect(SOCKET a, WSAEVENT b, long c);
BOOL PASCAL stub_WSAGetOverlappedResult(SOCKET a, LPWSAOVERLAPPED b, LPDWORD c, BOOL d, LPDWORD e);
BOOL PASCAL stub_WSAGetQOSByName(SOCKET a, LPWSABUF b, LPQOS c);
INT PASCAL stub_WSAGetServiceClassInfoA(LPGUID a, LPGUID b, LPDWORD c, LPWSASERVICECLASSINFOA d);
INT PASCAL stub_WSAGetServiceClassInfoW(LPGUID a, LPGUID b, LPDWORD c, LPWSASERVICECLASSINFOW d);
INT PASCAL stub_WSAGetServiceClassNameByClassIdA(LPGUID a, LPSTR b, LPDWORD c);
INT PASCAL stub_WSAGetServiceClassNameByClassIdW(LPGUID a, LPWSTR b, LPDWORD c);
int PASCAL stub_WSAHtonl(SOCKET a, u_long b, u_long* c);
int PASCAL stub_WSAHtons(SOCKET a, u_short b, u_short* c);
PHOSTENT PASCAL stub_gethostbyaddr(const char * a, int b, int c);
PHOSTENT PASCAL stub_gethostbyname(const char * a);
PPROTOENT PASCAL stub_getprotobyname(const char * a);
PPROTOENT PASCAL stub_getprotobynumber(int a);
PSERVENT PASCAL stub_getservbyname(const char * a, const char * b);
PSERVENT PASCAL stub_getservbyport(int a, const char * b);
int PASCAL stub_gethostname(char * a, int b);
INT PASCAL stub_WSAInstallServiceClassA(LPWSASERVICECLASSINFOA a);
INT PASCAL stub_WSAInstallServiceClassW(LPWSASERVICECLASSINFOW a);
int PASCAL stub_WSAIoctl(SOCKET a, DWORD b, LPVOID c, DWORD d, LPVOID e, DWORD g, LPDWORD h, LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j);
SOCKET PASCAL stub_WSAJoinLeaf(SOCKET a, const struct sockaddr* b, int c, LPWSABUF d, LPWSABUF e, LPQOS g, LPQOS h, DWORD i);
INT PASCAL stub_WSALookupServiceBeginA(LPWSAQUERYSETA a, DWORD b, LPHANDLE c);
INT PASCAL stub_WSALookupServiceBeginW(LPWSAQUERYSETW a, DWORD b, LPHANDLE c);
INT PASCAL stub_WSALookupServiceEnd(HANDLE a);
INT PASCAL stub_WSALookupServiceNextA(HANDLE a, DWORD b, LPDWORD c, LPWSAQUERYSETA d);
INT PASCAL stub_WSALookupServiceNextW(HANDLE a, DWORD b, LPDWORD c, LPWSAQUERYSETW d);
INT PASCAL stub_WSANSPIoctl(HANDLE a, DWORD b, LPVOID c, DWORD d, LPVOID e, DWORD g, LPDWORD h, LPWSACOMPLETION i);
int PASCAL stub_WSANtohl(SOCKET a, u_long b, u_long* c);
int PASCAL stub_WSANtohs(SOCKET a, u_short b, u_short* c);
INT PASCAL stub_WSAProviderConfigChange(LPHANDLE a, LPWSAOVERLAPPED b, LPWSAOVERLAPPED_COMPLETION_ROUTINE c);
int PASCAL stub_WSARecv(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, LPDWORD e, LPWSAOVERLAPPED g, LPWSAOVERLAPPED_COMPLETION_ROUTINE h);
int PASCAL stub_WSARecvDisconnect(SOCKET a, LPWSABUF b);
int PASCAL stub_WSARecvFrom(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, LPDWORD e, struct sockaddr* g, LPINT h,LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j);
INT PASCAL stub_WSARemoveServiceClass(LPGUID a);
BOOL PASCAL stub_WSAResetEvent(WSAEVENT a);
int PASCAL stub_WSASend(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, DWORD e, LPWSAOVERLAPPED g, LPWSAOVERLAPPED_COMPLETION_ROUTINE h);
int PASCAL stub_WSASendDisconnect(SOCKET a, LPWSABUF b);
int PASCAL stub_WSASendTo(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, DWORD e, const struct sockaddr* g, int h, LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j);
BOOL PASCAL stub_WSASetEvent(WSAEVENT a);
INT PASCAL stub_WSASetServiceA(LPWSAQUERYSETA a, WSAESETSERVICEOP b, DWORD c);
INT PASCAL stub_WSASetServiceW(LPWSAQUERYSETW a, WSAESETSERVICEOP b, DWORD c);
SOCKET PASCAL stub_WSASocketA(int a, int b, int c, LPWSAPROTOCOL_INFOA d, GROUP e, DWORD g);
SOCKET PASCAL stub_WSASocketW(int a, int b, int c, LPWSAPROTOCOL_INFOW d, GROUP e, DWORD g);
INT PASCAL stub_WSAStringToAddressA(LPSTR a, INT b, LPWSAPROTOCOL_INFOA c, LPSOCKADDR d, LPINT e);
INT PASCAL stub_WSAStringToAddressW(LPWSTR a, INT b, LPWSAPROTOCOL_INFOW c, LPSOCKADDR d, LPINT e);
DWORD PASCAL stub_WSAWaitForMultipleEvents(DWORD a, const WSAEVENT* b, BOOL c, DWORD d, BOOL e);
int PASCAL stub_WSCDeinstallProvider(LPGUID a, LPINT b);
INT PASCAL stub_WSCEnableNSProvider(LPGUID a, BOOL b);
int PASCAL stub_WSCEnumProtocols(LPINT a, /*LPWSAPROTOCOL_INFOW*/void * b, LPDWORD c, LPINT d);
int PASCAL stub_WSCGetProviderPath(LPGUID a, WCHAR* b, LPINT c, LPINT d);
INT PASCAL stub_WSCInstallNameSpace(LPWSTR a, LPWSTR b, DWORD c, DWORD d, LPGUID e);
int PASCAL stub_WSCInstallProvider(LPGUID a, const WCHAR* b, const LPWSAPROTOCOL_INFOW c, DWORD d, LPINT e);
INT PASCAL stub_WSCUnInstallNameSpace(LPGUID a);
int PASCAL stub_WSCUpdateProvider(LPGUID a, const WCHAR* b, const LPWSAPROTOCOL_INFOW c, DWORD d, LPINT e);
int PASCAL stub_WSCWriteNameSpaceOrder(LPGUID a, DWORD b);
int PASCAL stub_WSCWriteProviderOrder(LPDWORD a, DWORD b);
VOID PASCAL stub_freeaddrinfo(/*PADDRINFOA*/void * a);
INT PASCAL stub_getaddrinfo(PCSTR a, PCSTR b, const /*ADDRINFOA*/void * c, /*PADDRINFOA*/void * d);
INT PASCAL stub_getnameinfo(const SOCKADDR * a, /*socklen_t*/void * b, PCHAR c, DWORD d, PCHAR e, DWORD g, INT h);
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

#endif // WS2_32_STUBS_H
