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

#include "wsock32_stubs.h"
#include <windows.h>
#include <winsock.h>
#include "wsock32_funcs.h"

unsigned int PASCAL stub_accept(unsigned int a, PSOCKADDR b, int * c)
{
	if (g_f_addr[F_accept])
	{
		unsigned int PASCAL (* f)(unsigned int, PSOCKADDR, int *) = g_f_addr[F_accept];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[accept] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_bind(unsigned int a, const SOCKADDR * b, int c)
{
	if (g_f_addr[F_bind])
	{
		int PASCAL (* f)(unsigned int, const SOCKADDR *, int) = g_f_addr[F_bind];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[bind] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_closesocket(unsigned int a)
{
	if (g_f_addr[F_closesocket])
	{
		int PASCAL (* f)(unsigned int) = g_f_addr[F_closesocket];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[closesocket] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_connect(unsigned int a, const SOCKADDR * b, int c)
{
	if (g_f_addr[F_connect])
	{
		int PASCAL (* f)(unsigned int, const SOCKADDR *, int) = g_f_addr[F_connect];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[connect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_getpeername(unsigned int a, PSOCKADDR b, int * c)
{
	if (g_f_addr[F_getpeername])
	{
		int PASCAL (* f)(unsigned int, PSOCKADDR, int *) = g_f_addr[F_getpeername];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getpeername] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_getsockname(unsigned int a, PSOCKADDR b, int * c)
{
	if (g_f_addr[F_getsockname])
	{
		int PASCAL (* f)(unsigned int, PSOCKADDR, int *) = g_f_addr[F_getsockname];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getsockname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_getsockopt(unsigned int a, int b, int c, char * d, int * e)
{
	if (g_f_addr[F_getsockopt])
	{
		int PASCAL (* f)(unsigned int, int, int, char *, int *) = g_f_addr[F_getsockopt];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getsockopt] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned long int PASCAL stub_htonl(unsigned long int a)
{
	if (g_f_addr[F_htonl])
	{
		unsigned long int PASCAL (* f)(unsigned long int) = g_f_addr[F_htonl];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[htonl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned short int PASCAL stub_htons(unsigned short int a)
{
	if (g_f_addr[F_htons])
	{
		unsigned short int PASCAL (* f)(unsigned short int) = g_f_addr[F_htons];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[htons] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned long int PASCAL stub_inet_addr(const char * a)
{
	if (g_f_addr[F_inet_addr])
	{
		unsigned long int PASCAL (* f)(const char *) = g_f_addr[F_inet_addr];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[inet_addr] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

char * PASCAL stub_inet_ntoa(IN_ADDR a)
{
	if (g_f_addr[F_inet_ntoa])
	{
		char * PASCAL (* f)(IN_ADDR) = g_f_addr[F_inet_ntoa];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[inet_ntoa] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_ioctlsocket(unsigned int a, long int b, unsigned long int * c)
{
	if (g_f_addr[F_ioctlsocket])
	{
		int PASCAL (* f)(unsigned int, long int, unsigned long int *) = g_f_addr[F_ioctlsocket];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[ioctlsocket] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_listen(unsigned int a, int b)
{
	if (g_f_addr[F_listen])
	{
		int PASCAL (* f)(unsigned int, int) = g_f_addr[F_listen];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[listen] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned long int PASCAL stub_ntohl(unsigned long int a)
{
	if (g_f_addr[F_ntohl])
	{
		unsigned long int PASCAL (* f)(unsigned long int) = g_f_addr[F_ntohl];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[ntohl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned short int PASCAL stub_ntohs(unsigned short int a)
{
	if (g_f_addr[F_ntohl])
	{
		unsigned short int PASCAL (* f)(unsigned short int) = g_f_addr[F_ntohs];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[ntohl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_recv(unsigned int a, char * b, int c, int d)
{
	if (g_f_addr[F_recv])
	{
		int PASCAL (* f)(unsigned int, char *, int, int) = g_f_addr[F_recv];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[recv] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_recvfrom(unsigned int a, char * b, int c, int d, PSOCKADDR e, int * g)
{
	if (g_f_addr[F_recvfrom])
	{
		int PASCAL (* f)(unsigned int, char *, int, int, PSOCKADDR, int *) = g_f_addr[F_recvfrom];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[recvfrom] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_select(int a, PFD_SET b, PFD_SET c, PFD_SET d, const TIMEVAL * e)
{
	if (g_f_addr[F_select])
	{
		int PASCAL (* f)(int, PFD_SET, PFD_SET, PFD_SET, const TIMEVAL *) = g_f_addr[F_select];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[select] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_send(unsigned int a , const char * b, int c, int d)
{
	if (g_f_addr[F_send])
	{
		int PASCAL (* f)(unsigned int, const char *, int, int) = g_f_addr[F_send];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[send] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_sendto(unsigned int a, const char * b, int c, int d, const SOCKADDR * e, int g)
{
	if (g_f_addr[F_sendto])
	{
		int PASCAL (* f)(unsigned int, const char *, int, int, const SOCKADDR *, int) = g_f_addr[F_sendto];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[sendto] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_setsockopt(unsigned int a, int b, int c, const char * d, int e)
{
	if (g_f_addr[F_setsockopt])
	{
		int PASCAL (* f)(unsigned int, int, int, const char *, int) = g_f_addr[F_setsockopt];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[setsockopt] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_shutdown(unsigned int a, int b)
{
	if (g_f_addr[F_shutdown])
	{
		int PASCAL (* f)(unsigned int, int) = g_f_addr[F_shutdown];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[shutdown] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

unsigned int PASCAL stub_socket(int a, int b, int c)
{
	if (g_f_addr[F_socket])
	{
		unsigned int PASCAL (* f)(int, int, int) = g_f_addr[F_socket];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[socket] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_MigrateWinsockConfiguration(DWORD a, DWORD b, DWORD c)
{
	if (g_f_addr[F_MigrateWinsockConfiguration])
	{
		INT PASCAL (* f)(DWORD, DWORD, DWORD) = g_f_addr[F_MigrateWinsockConfiguration];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[MigrateWinsockConfiguration] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PHOSTENT PASCAL stub_gethostbyaddr(const char * a, int b, int c)
{
	if (g_f_addr[F_gethostbyaddr])
	{
		PHOSTENT PASCAL (* f)(const char *, int, int) = g_f_addr[F_gethostbyaddr];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[gethostbyaddr] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PHOSTENT PASCAL stub_gethostbyname(const char * a)
{
	if (g_f_addr[F_gethostbyname])
	{
		PHOSTENT PASCAL (* f)(const char *) = g_f_addr[F_gethostbyname];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[gethostbyname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PPROTOENT PASCAL stub_getprotobyname(const char * a)
{
	if (g_f_addr[F_getprotobyname])
	{
		PPROTOENT PASCAL (* f)(const char *) = g_f_addr[F_getprotobyname];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getprotobyname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PPROTOENT PASCAL stub_getprotobynumber(int a)
{
	if (g_f_addr[F_getprotobynumber])
	{
		PPROTOENT PASCAL (* f)(int) = g_f_addr[F_getprotobynumber];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getprotobynumber] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PSERVENT PASCAL stub_getservbyname(const char * a, const char * b)
{
	if (g_f_addr[F_getservbyname])
	{
		PSERVENT PASCAL (* f)(const char *, const char *) = g_f_addr[F_getservbyname];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getservbyname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

PSERVENT PASCAL stub_getservbyport(int a, const char * b)
{
	if (g_f_addr[F_getservbyport])
	{
		PSERVENT PASCAL (* f)(int, const char *) = g_f_addr[F_getservbyport];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getservbyport] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_gethostname(char * a, int b)
{
	if (g_f_addr[F_gethostname])
	{
		int PASCAL (* f)(char *, int) = g_f_addr[F_gethostname];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[gethostname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAAsyncSelect(unsigned int a, HWND b, unsigned int c, long int d)
{
	if (g_f_addr[F_WSAAsyncSelect])
	{
		int PASCAL (* f)(unsigned int, HWND, unsigned int, long int) = g_f_addr[F_WSAAsyncSelect];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncSelect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}
void * PASCAL stub_WSAAsyncGetHostByAddr(HWND a, unsigned int b, const char * c, int d, int e, char * g, int h)
{
	if (g_f_addr[F_WSAAsyncGetHostByAddr])
	{
		void * PASCAL (* f)(HWND, unsigned int, const char *, int, int, char *, int) = g_f_addr[F_WSAAsyncGetHostByAddr];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetHostByAddr] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSAAsyncGetHostByName(HWND a, unsigned int b, const char * c, char * d, int e)
{
	if (g_f_addr[F_WSAAsyncGetHostByName])
	{
		void * PASCAL (* f)(HWND, unsigned int, const char *, char *, int) = g_f_addr[F_WSAAsyncGetHostByName];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetHostByName] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSAAsyncGetProtoByNumber(HWND a, unsigned int b, int c, char * d, int e)
{
	if (g_f_addr[F_WSAAsyncGetProtoByNumber])
	{
		void * PASCAL (* f)(HWND, unsigned int, int, char *, int) = g_f_addr[F_WSAAsyncGetProtoByNumber];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetProtoByNumber] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSAAsyncGetProtoByName(HWND a, unsigned int b, const char * c, char * d, int e)
{
	if (g_f_addr[F_WSAAsyncGetProtoByName])
	{
		void * PASCAL (* f)(HWND, unsigned int, const char *, char *, int) = g_f_addr[F_WSAAsyncGetProtoByName];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetProtoByName] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSAAsyncGetServByPort(HWND a, unsigned int b, int c, const char * d, char * e, int g)
{
	if (g_f_addr[F_WSAAsyncGetServByPort])
	{
		void * PASCAL (* f)(HWND, unsigned int, int, const char *, char *, int) = g_f_addr[F_WSAAsyncGetServByPort];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetServByPort] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSAAsyncGetServByName(HWND a, unsigned int b, const char * c, const char * d, char * e, int g)
{
	if (g_f_addr[F_WSAAsyncGetServByName])
	{
		void * PASCAL (* f)(HWND, unsigned int, const char *, const char *, char *, int) = g_f_addr[F_WSAAsyncGetServByName];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAsyncGetServByName] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSACancelAsyncRequest(void * a)
{
	if (g_f_addr[F_WSACancelAsyncRequest])
	{
		int PASCAL (* f)(void *) = g_f_addr[F_WSACancelAsyncRequest];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSACancelAsyncRequest] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void * PASCAL stub_WSASetBlockingHook(void * a)
{
	if (g_f_addr[F_WSASetBlockingHook])
	{
		void * PASCAL (* f)(void *) = g_f_addr[F_WSASetBlockingHook];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASetBlockingHook] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAUnhookBlockingHook(void)
{
	if (g_f_addr[F_WSAUnhookBlockingHook])
	{
		int PASCAL (* f)(void) = g_f_addr[F_WSAUnhookBlockingHook];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAUnhookBlockingHook] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAGetLastError(void)
{
	if (g_f_addr[F_WSAGetLastError])
	{
		int PASCAL (* f)(void) = g_f_addr[F_WSAGetLastError];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetLastError] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void PASCAL stub_WSASetLastError(int a)
{
	if (g_f_addr[F_WSASetLastError])
	{
		void PASCAL (* f)(int) = g_f_addr[F_WSASetLastError];
		f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASetLastError] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
}

int PASCAL stub_WSACancelBlockingCall(void)
{
	if (g_f_addr[F_WSACancelBlockingCall])
	{
		int PASCAL (* f)(void) = g_f_addr[F_WSACancelBlockingCall];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSACancelBlockingCall] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAIsBlocking(void)
{
	if (g_f_addr[F_WSAIsBlocking])
	{
		int PASCAL (* f)(void) = g_f_addr[F_WSAIsBlocking];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAIsBlocking] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAStartup(unsigned short int a, LPWSADATA b)
{
	if (g_f_addr[F_WSAStartup])
	{
		int PASCAL (* f)(unsigned short int, LPWSADATA) = g_f_addr[F_WSAStartup];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAStartup] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSACleanup(void)
{
	if (g_f_addr[F_WSACleanup])
	{
		int PASCAL (* f)(void) = g_f_addr[F_WSACleanup];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSACleanup] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub___WSAFDIsSet(unsigned int a, PFD_SET b)
{
	if (g_f_addr[F___WSAFDIsSet])
	{
		int PASCAL (* f)(unsigned int, PFD_SET) = g_f_addr[F___WSAFDIsSet];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[__WSAFDIsSet] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WEP(DWORD a)
{
	if (g_f_addr[F_WEP])
	{
		BOOL PASCAL (* f)(DWORD) = g_f_addr[F_WEP];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WEP] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSApSetPostRoutine(PVOID a)
{
	if (g_f_addr[F_WSApSetPostRoutine])
	{
		BOOL PASCAL (* f)(PVOID) = g_f_addr[F_WSApSetPostRoutine];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSApSetPostRoutine] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

UINT PASCAL stub_inet_network(const char * a)
{
	if (g_f_addr[F_inet_network])
	{
		UINT PASCAL (* f)(const char *) = g_f_addr[F_inet_network];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[inet_network] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void */*substitution type (struct netent*)*/ PASCAL stub_getnetbyname(const char * a)
{
	if (g_f_addr[F_getnetbyname])
	{
		void * PASCAL (* f)(const char *) = g_f_addr[F_getnetbyname];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getnetbyname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_rcmd(char ** a, USHORT b, char *	c, char * d, char * e, int * g)
{
	if (g_f_addr[F_rcmd])
	{
		SOCKET PASCAL (* f)(char **, USHORT, char *, char *, char *, int *) = g_f_addr[F_rcmd];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[rcmd] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_rexec(char ** a, USHORT b, char *	c, char * d, char * e, int * g)
{
	if (g_f_addr[F_rexec])
	{
		SOCKET PASCAL (* f)(char **, USHORT, char *, char *, char *, int *) = g_f_addr[F_rexec];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[rexec] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_rresvport(int * a)
{
	if (g_f_addr[F_rresvport])
	{
		SOCKET PASCAL (* f)(int *) = g_f_addr[F_rresvport];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[rresvport] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_sethostname(char * a, int b)
{
	if (g_f_addr[F_sethostname])
	{
		SOCKET PASCAL (* f)(char *, int) = g_f_addr[F_sethostname];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[sethostname] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_dn_expand(unsigned char * a, unsigned char * b, unsigned char * c, unsigned char * d, int e)
{
	if (g_f_addr[F_dn_expand])
	{
		SOCKET PASCAL (* f)(unsigned char *, unsigned char *, unsigned char *, unsigned char *, int) = g_f_addr[F_dn_expand];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[dn_expand] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSARecvEx(unsigned int a, char * b, int c, int * d)
{
	if (g_f_addr[F_WSARecvEx])
	{
		SOCKET PASCAL (* f)(unsigned int, char *, int, int *) = g_f_addr[F_WSARecvEx];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSARecvEx] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

void PASCAL stub_s_perror(const char * a)
{
	if (g_f_addr[F_s_perror])
	{
		SOCKET PASCAL (* f)(const char *) = g_f_addr[F_s_perror];
		f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[s_perror] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
}

INT PASCAL stub_GetAddressByNameA(DWORD a, LPGUID b, LPSTR c, LPINT d, DWORD e, void * g/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPVOID h, LPDWORD i, LPSTR j, LPDWORD k)
{
	if (g_f_addr[F_GetAddressByNameA])
	{
		INT PASCAL (* f)(DWORD, LPGUID, LPSTR, LPINT, DWORD, void *, LPVOID, LPDWORD, LPSTR, LPDWORD) = g_f_addr[F_GetAddressByNameA];
		return f(a, b, c, d, e, g, h, i, j, k);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetAddressByNameA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetAddressByNameW(DWORD a, LPGUID b, LPWSTR c, LPINT d, DWORD e, void * g/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPVOID h, LPDWORD i, LPWSTR j, LPDWORD k)
{
	if (g_f_addr[F_GetAddressByNameW])
	{
		INT PASCAL (* f)(DWORD, LPGUID, LPWSTR, LPINT, DWORD, void *, LPVOID, LPDWORD, LPWSTR, LPDWORD) = g_f_addr[F_GetAddressByNameW];
		return f(a, b, c, d, e, g, h, i, j, k);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetAddressByNameW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_EnumProtocolsA(LPINT a, LPVOID b, LPDWORD c)
{
	if (g_f_addr[F_EnumProtocolsA])
	{
		INT PASCAL (* f)(LPINT , LPVOID , LPDWORD) = g_f_addr[F_EnumProtocolsA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[EnumProtocolsA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_EnumProtocolsW(LPINT a, LPVOID b, LPDWORD c)
{
	if (g_f_addr[F_EnumProtocolsW])
	{
		INT PASCAL (* f)(LPINT , LPVOID , LPDWORD) = g_f_addr[F_EnumProtocolsW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[EnumProtocolsW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetTypeByNameA(LPSTR a, LPGUID b)
{
	if (g_f_addr[F_GetTypeByNameA])
	{
		INT PASCAL (* f)(LPSTR , LPGUID) = g_f_addr[F_GetTypeByNameA];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetTypeByNameA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetTypeByNameW(LPWSTR a, LPGUID b)
{
	if (g_f_addr[F_GetTypeByNameW])
	{
		INT PASCAL (* f)(LPWSTR , LPGUID) = g_f_addr[F_GetTypeByNameW];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetTypeByNameW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetNameByTypeA(LPGUID a, LPSTR b, DWORD c)
{
	if (g_f_addr[F_GetNameByTypeA])
	{
		INT PASCAL (* f)(LPGUID , LPSTR , DWORD) = g_f_addr[F_GetNameByTypeA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetNameByTypeA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetNameByTypeW(LPGUID a, LPWSTR b, DWORD c)
{
	if (g_f_addr[F_GetNameByTypeW])
	{
		INT PASCAL (* f)(LPGUID , LPWSTR , DWORD) = g_f_addr[F_GetNameByTypeW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetNameByTypeW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_SetServiceA(DWORD a, DWORD b, DWORD c, void * d/*substitution type (LPSERVICE_INFOA)*/, void * e/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPDWORD g)
{
	if (g_f_addr[F_SetServiceA])
	{
		INT PASCAL (* f)(DWORD, DWORD, DWORD, void *, void *, LPDWORD) = g_f_addr[F_SetServiceA];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[SetServiceA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_SetServiceW(DWORD a, DWORD b, DWORD c, void * d/*substitution type (LPSERVICE_INFOW)*/, void * e/*substitution type (LPSERVICE_ASYNC_INFO)*/, LPDWORD g)
{
	if (g_f_addr[F_SetServiceW])
	{
		INT PASCAL (* f)(DWORD, DWORD, DWORD, void *, void *, LPDWORD) = g_f_addr[F_SetServiceW];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[SetServiceW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetServiceA(DWORD a, LPGUID b, LPSTR c, DWORD d, LPVOID e, LPDWORD g, void * h/*substitution type (LPSERVICE_ASYNC_INFO)*/)
{
	if (g_f_addr[F_GetServiceA])
	{
		INT PASCAL (* f)(DWORD, LPGUID, LPSTR, DWORD, LPVOID, LPDWORD, void *) = g_f_addr[F_GetServiceA];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetServiceA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetServiceW(DWORD a, LPGUID b, LPWSTR c, DWORD d, LPVOID e, LPDWORD g, void * h/*substitution type (LPSERVICE_ASYNC_INFO)*/)
{
	if (g_f_addr[F_GetServiceW])
	{
		INT PASCAL (* f)(DWORD, LPGUID, LPWSTR, DWORD, LPVOID, LPDWORD, void *) = g_f_addr[F_GetServiceW];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetServiceW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_NPLoadNameSpaces(LPDWORD a, void */*substitution type (LPNS_ROUTINE)*/ b, LPDWORD c)
{
	if (g_f_addr[F_NPLoadNameSpaces])
	{
		INT PASCAL (* f)(LPDWORD, void *, LPDWORD) = g_f_addr[F_NPLoadNameSpaces];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[NPLoadNameSpaces] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_TransmitFile(SOCKET a, HANDLE b, DWORD c, DWORD d, LPOVERLAPPED e, LPTRANSMIT_FILE_BUFFERS g, DWORD h)
{
	if (g_f_addr[F_TransmitFile])
	{
		BOOL PASCAL (* f)(SOCKET, HANDLE, DWORD, DWORD, LPOVERLAPPED, LPTRANSMIT_FILE_BUFFERS, DWORD) = g_f_addr[F_TransmitFile];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[TransmitFile] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_AcceptEx(SOCKET a, SOCKET b, PVOID c, DWORD d, DWORD e, DWORD g, LPDWORD h, LPOVERLAPPED i)
{
	if (g_f_addr[F_AcceptEx])
	{
		BOOL PASCAL (* f)(SOCKET, SOCKET, PVOID, DWORD, DWORD, DWORD, LPDWORD, LPOVERLAPPED) = g_f_addr[F_AcceptEx];
		return f(a, b, c, d, e, g, h, i);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[AcceptEx] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

VOID PASCAL stub_GetAcceptExSockaddrs(PVOID a, DWORD b, DWORD c, DWORD d, PSOCKADDR * e, LPINT g, PSOCKADDR * h, LPINT i)
{
	if (g_f_addr[F_GetAcceptExSockaddrs])
	{
		VOID PASCAL (* f)(PVOID, DWORD, DWORD, DWORD, PSOCKADDR *, LPINT, PSOCKADDR *, LPINT) = g_f_addr[F_GetAcceptExSockaddrs];
		f(a, b, c, d, e, g, h, i);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetAcceptExSockaddrs] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
}
