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

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "ws2_32_stubs.h"
#include <windows.h>
#include <winsock2.h>
#include "ws2_32_funcs.h"

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

INT PASCAL stub_GetAddrInfoW(PCWSTR a, PCWSTR b, const /*ADDRINFOW*/void * c, /*PADDRINFOW*/void * d)
{
	if (g_f_addr[F_GetAddrInfoW])
	{
		INT PASCAL (* f)(PCWSTR, PCWSTR, const /*ADDRINFOW*/void *, /*PADDRINFOW*/void *) = g_f_addr[F_GetAddrInfoW];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetAddrInfoW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_GetNameInfoW(const SOCKADDR * a, /*socklen_t*/int b, PWCHAR c, DWORD d, PWCHAR e, DWORD g, INT h)
{
	if (g_f_addr[F_GetNameInfoW])
	{
		INT PASCAL (* f)(const SOCKADDR *, /*socklen_t*/int, PWCHAR, DWORD, PWCHAR, DWORD, INT) = g_f_addr[F_GetNameInfoW];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[GetNameInfoW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
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

VOID PASCAL stub_FreeAddrInfoW(PVOID a)
{
	if (g_f_addr[F_FreeAddrInfoW])
	{
		VOID PASCAL (* f)(PVOID) = g_f_addr[F_FreeAddrInfoW];
		f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[FreeAddrInfoW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
}

int PASCAL stub_WPUCompleteOverlappedRequest(SOCKET a, LPWSAOVERLAPPED b, DWORD c, DWORD d, LPINT e)
{
	if (g_f_addr[F_WPUCompleteOverlappedRequest])
	{
		int PASCAL (* f)(SOCKET, LPWSAOVERLAPPED, DWORD, DWORD, LPINT) = g_f_addr[F_WPUCompleteOverlappedRequest];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WPUCompleteOverlappedRequest] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_WSAAccept(SOCKET a, struct sockaddr* b, LPINT c, LPCONDITIONPROC d, DWORD_PTR e)
{
	if (g_f_addr[F_WSAAccept])
	{
		SOCKET PASCAL (* f)(SOCKET, struct sockaddr*, LPINT, LPCONDITIONPROC, DWORD_PTR) = g_f_addr[F_WSAAccept];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAccept] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAAddressToStringA(LPSOCKADDR a, DWORD b, LPWSAPROTOCOL_INFOA c, LPSTR d, LPDWORD e)
{
	if (g_f_addr[F_WSAAddressToStringA])
	{
		INT PASCAL (* f)(LPSOCKADDR, DWORD, LPWSAPROTOCOL_INFOA, LPSTR, LPDWORD) = g_f_addr[F_WSAAddressToStringA];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAddressToStringA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAAddressToStringW(LPSOCKADDR a, DWORD b, LPWSAPROTOCOL_INFOW c, LPWSTR d, LPDWORD e)
{
	if (g_f_addr[F_WSAAddressToStringW])
	{
		INT PASCAL (* f)(LPSOCKADDR, DWORD, LPWSAPROTOCOL_INFOW, LPWSTR, LPDWORD) = g_f_addr[F_WSAAddressToStringW];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAAddressToStringW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSACloseEvent(WSAEVENT a)
{
	if (g_f_addr[F_WSACloseEvent])
	{
		BOOL PASCAL (* f)(WSAEVENT) = g_f_addr[F_WSACloseEvent];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSACloseEvent] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAConnect(SOCKET a, const struct sockaddr* b, int c, LPWSABUF d, LPWSABUF e, LPQOS g, LPQOS h)
{
	if (g_f_addr[F_WSAConnect])
	{
		int PASCAL (* f)(SOCKET, const struct sockaddr*, int, LPWSABUF, LPWSABUF, LPQOS, LPQOS) = g_f_addr[F_WSAConnect];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAConnect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

WSAEVENT PASCAL stub_WSACreateEvent(void)
{
	if (g_f_addr[F_WSACreateEvent])
	{
		WSAEVENT PASCAL (* f)(void) = g_f_addr[F_WSACreateEvent];
		return f();
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSACreateEvent] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSADuplicateSocketA(SOCKET a, DWORD b, LPWSAPROTOCOL_INFOA c)
{
	if (g_f_addr[F_WSADuplicateSocketA])
	{
		int PASCAL (* f)(SOCKET, DWORD, LPWSAPROTOCOL_INFOA) = g_f_addr[F_WSADuplicateSocketA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSADuplicateSocketA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSADuplicateSocketW(SOCKET a, DWORD b, LPWSAPROTOCOL_INFOW c)
{
	if (g_f_addr[F_WSADuplicateSocketW])
	{
		int PASCAL (* f)(SOCKET, DWORD, LPWSAPROTOCOL_INFOW) = g_f_addr[F_WSADuplicateSocketW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSADuplicateSocketW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAEnumNameSpaceProvidersA(LPDWORD a, LPWSANAMESPACE_INFOA b)
{
	if (g_f_addr[F_WSAEnumNameSpaceProvidersA])
	{
		INT PASCAL (* f)(LPDWORD, LPWSANAMESPACE_INFOA) = g_f_addr[F_WSAEnumNameSpaceProvidersA];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumNameSpaceProvidersA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAEnumNameSpaceProvidersW(LPDWORD a, LPWSANAMESPACE_INFOW b)
{
	if (g_f_addr[F_WSAEnumNameSpaceProvidersW])
	{
		INT PASCAL (* f)(LPDWORD, LPWSANAMESPACE_INFOW) = g_f_addr[F_WSAEnumNameSpaceProvidersW];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumNameSpaceProvidersW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAEnumNetworkEvents(SOCKET a, WSAEVENT b, LPWSANETWORKEVENTS c)
{
	if (g_f_addr[F_WSAEnumNetworkEvents])
	{
		int PASCAL (* f)(SOCKET, WSAEVENT, LPWSANETWORKEVENTS) = g_f_addr[F_WSAEnumNetworkEvents];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumNetworkEvents] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAEnumProtocolsA(LPINT a, LPWSAPROTOCOL_INFOA b, LPDWORD c)
{
	if (g_f_addr[F_WSAEnumProtocolsA])
	{
		int PASCAL (* f)(LPINT, LPWSAPROTOCOL_INFOA, LPDWORD) = g_f_addr[F_WSAEnumProtocolsA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumProtocolsA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAEnumProtocolsW(LPINT a, LPWSAPROTOCOL_INFOW b, LPDWORD c)
{
	if (g_f_addr[F_WSAEnumProtocolsW])
	{
		int PASCAL (* f)(LPINT, LPWSAPROTOCOL_INFOW, LPDWORD) = g_f_addr[F_WSAEnumProtocolsW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumProtocolsW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAEventSelect(SOCKET a, WSAEVENT b, long c)
{
	if (g_f_addr[F_WSAEventSelect])
	{
		int PASCAL (* f)(SOCKET, WSAEVENT, long) = g_f_addr[F_WSAEventSelect];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEventSelect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSAGetOverlappedResult(SOCKET a, LPWSAOVERLAPPED b, LPDWORD c, BOOL d, LPDWORD e)
{
	if (g_f_addr[F_WSAGetOverlappedResult])
	{
		BOOL PASCAL (* f)(SOCKET, LPWSAOVERLAPPED, LPDWORD, BOOL, LPDWORD) = g_f_addr[F_WSAGetOverlappedResult];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetOverlappedResult] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSAGetQOSByName(SOCKET a, LPWSABUF b, LPQOS c)
{
	if (g_f_addr[F_WSAGetQOSByName])
	{
		BOOL PASCAL (* f)(SOCKET, LPWSABUF, LPQOS) = g_f_addr[F_WSAGetQOSByName];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetQOSByName] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAGetServiceClassInfoA(LPGUID a, LPGUID b, LPDWORD c, LPWSASERVICECLASSINFOA d)
{
	if (g_f_addr[F_WSAGetServiceClassInfoA])
	{
		INT PASCAL (* f)(LPGUID, LPGUID, LPDWORD, LPWSASERVICECLASSINFOA) = g_f_addr[F_WSAGetServiceClassInfoA];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetServiceClassInfoA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAGetServiceClassInfoW(LPGUID a, LPGUID b, LPDWORD c, LPWSASERVICECLASSINFOW d)
{
	if (g_f_addr[F_WSAEnumNameSpaceProvidersW])
	{
		INT PASCAL (* f)(LPGUID, LPGUID, LPDWORD, LPWSASERVICECLASSINFOW) = g_f_addr[F_WSAEnumNameSpaceProvidersW];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAEnumNameSpaceProvidersW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAGetServiceClassNameByClassIdA(LPGUID a, LPSTR b, LPDWORD c)
{
	if (g_f_addr[F_WSAGetServiceClassNameByClassIdA])
	{
		INT PASCAL (* f)(LPGUID, LPSTR, LPDWORD) = g_f_addr[F_WSAGetServiceClassNameByClassIdA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetServiceClassNameByClassIdA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAGetServiceClassNameByClassIdW(LPGUID a, LPWSTR b, LPDWORD c)
{
	if (g_f_addr[F_WSAGetServiceClassNameByClassIdW])
	{
		INT PASCAL (* f)(LPGUID, LPWSTR, LPDWORD) = g_f_addr[F_WSAGetServiceClassNameByClassIdW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAGetServiceClassNameByClassIdW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAHtonl(SOCKET a, u_long b, u_long* c)
{
	if (g_f_addr[F_WSAHtonl])
	{
		int PASCAL (* f)(SOCKET, u_long, u_long*) = g_f_addr[F_WSAHtonl];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAHtonl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAHtons(SOCKET a, u_short b, u_short* c)
{
	if (g_f_addr[F_WSAHtons])
	{
		int PASCAL (* f)(SOCKET, u_short, u_short*) = g_f_addr[F_WSAHtons];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAHtons] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
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

INT PASCAL stub_WSAInstallServiceClassA(LPWSASERVICECLASSINFOA a)
{
	if (g_f_addr[F_WSAInstallServiceClassA])
	{
		INT PASCAL (* f)(LPWSASERVICECLASSINFOA) = g_f_addr[F_WSAInstallServiceClassA];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAInstallServiceClassA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAInstallServiceClassW(LPWSASERVICECLASSINFOW a)
{
	if (g_f_addr[F_WSAInstallServiceClassW])
	{
		INT PASCAL (* f)(LPWSASERVICECLASSINFOW) = g_f_addr[F_WSAInstallServiceClassW];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAInstallServiceClassW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSAIoctl(SOCKET a, DWORD b, LPVOID c, DWORD d, LPVOID e, DWORD g, LPDWORD h, LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j)
{
	if (g_f_addr[F_WSAIoctl])
	{
		int PASCAL (* f)(SOCKET, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSAIoctl];
		return f(a, b, c, d, e, g, h, i, j);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAIoctl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_WSAJoinLeaf(SOCKET a, const struct sockaddr* b, int c, LPWSABUF d, LPWSABUF e, LPQOS g, LPQOS h, DWORD i)
{
	if (g_f_addr[F_WSAJoinLeaf])
	{
		SOCKET PASCAL (* f)(SOCKET, const struct sockaddr*, int, LPWSABUF, LPWSABUF, LPQOS, LPQOS, DWORD) = g_f_addr[F_WSAJoinLeaf];
		return f(a, b, c, d, e, g, h, i);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAJoinLeaf] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSALookupServiceBeginA(LPWSAQUERYSETA a, DWORD b, LPHANDLE c)
{
	if (g_f_addr[F_WSALookupServiceBeginA])
	{
		INT PASCAL (* f)(LPWSAQUERYSETA, DWORD, LPHANDLE) = g_f_addr[F_WSALookupServiceBeginA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSALookupServiceBeginA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSALookupServiceBeginW(LPWSAQUERYSETW a, DWORD b, LPHANDLE c)
{
	if (g_f_addr[F_WSALookupServiceBeginW])
	{
		INT PASCAL (* f)(LPWSAQUERYSETW, DWORD, LPHANDLE) = g_f_addr[F_WSALookupServiceBeginW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSALookupServiceBeginW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSALookupServiceEnd(HANDLE a)
{
	if (g_f_addr[F_WSALookupServiceEnd])
	{
		INT PASCAL (* f)(HANDLE) = g_f_addr[F_WSALookupServiceEnd];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSALookupServiceEnd] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSALookupServiceNextA(HANDLE a, DWORD b, LPDWORD c, LPWSAQUERYSETA d)
{
	if (g_f_addr[F_WSALookupServiceNextA])
	{
		INT PASCAL (* f)(HANDLE, DWORD, LPDWORD, LPWSAQUERYSETA) = g_f_addr[F_WSALookupServiceNextA];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSALookupServiceNextA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSALookupServiceNextW(HANDLE a, DWORD b, LPDWORD c, LPWSAQUERYSETW d)
{
	if (g_f_addr[F_WSALookupServiceNextW])
	{
		INT PASCAL (* f)(HANDLE, DWORD, LPDWORD, LPWSAQUERYSETW) = g_f_addr[F_WSALookupServiceNextW];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSALookupServiceNextW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSANSPIoctl(HANDLE a, DWORD b, LPVOID c, DWORD d, LPVOID e, DWORD g, LPDWORD h, LPWSACOMPLETION i)
{
	if (g_f_addr[F_WSANSPIoctl])
	{
		INT PASCAL (* f)(HANDLE, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPWSACOMPLETION) = g_f_addr[F_WSANSPIoctl];
		return f(a, b, c, d, e, g, h, i);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSANSPIoctl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSANtohl(SOCKET a, u_long b, u_long* c)
{
	if (g_f_addr[F_WSANtohl])
	{
		int PASCAL (* f)(SOCKET, u_long, u_long*) = g_f_addr[F_WSANtohl];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSANtohl] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSANtohs(SOCKET a, u_short b, u_short* c)
{
	if (g_f_addr[F_WSANtohs])
	{
		int PASCAL (* f)(SOCKET, u_short, u_short*) = g_f_addr[F_WSANtohs];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSANtohs] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAProviderConfigChange(LPHANDLE a, LPWSAOVERLAPPED b, LPWSAOVERLAPPED_COMPLETION_ROUTINE c)
{
	if (g_f_addr[F_WSAProviderConfigChange])
	{
		INT PASCAL (* f)(LPHANDLE, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSAProviderConfigChange];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAProviderConfigChange] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSARecv(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, LPDWORD e, LPWSAOVERLAPPED g, LPWSAOVERLAPPED_COMPLETION_ROUTINE h)
{
	if (g_f_addr[F_WSARecv])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSARecv];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSARecv] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSARecvDisconnect(SOCKET a, LPWSABUF b)
{
	if (g_f_addr[F_WSARecvDisconnect])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF) = g_f_addr[F_WSARecvDisconnect];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSARecvDisconnect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSARecvFrom(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, LPDWORD e, struct sockaddr* g, LPINT h, LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j)
{
	if (g_f_addr[F_WSARecvFrom])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, struct sockaddr*, LPINT,LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSARecvFrom];
		return f(a, b, c, d, e, g, h, i, j);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSARecvFrom] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSARemoveServiceClass(LPGUID a)
{
	if (g_f_addr[F_WSARemoveServiceClass])
	{
		INT PASCAL (* f)(LPGUID) = g_f_addr[F_WSARemoveServiceClass];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSARemoveServiceClass] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSAResetEvent(WSAEVENT a)
{
	if (g_f_addr[F_WSAResetEvent])
	{
		BOOL PASCAL (* f)(WSAEVENT) = g_f_addr[F_WSAResetEvent];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAResetEvent] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSASend(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, DWORD e, LPWSAOVERLAPPED g, LPWSAOVERLAPPED_COMPLETION_ROUTINE h)
{
	if (g_f_addr[F_WSASend])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSASend];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASend] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSASendDisconnect(SOCKET a, LPWSABUF b)
{
	if (g_f_addr[F_WSASendDisconnect])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF) = g_f_addr[F_WSASendDisconnect];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASendDisconnect] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSASendTo(SOCKET a, LPWSABUF b, DWORD c, LPDWORD d, DWORD e, const struct sockaddr* g, int h, LPWSAOVERLAPPED i, LPWSAOVERLAPPED_COMPLETION_ROUTINE j)
{
	if (g_f_addr[F_WSASendTo])
	{
		int PASCAL (* f)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, const struct sockaddr*, int, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE) = g_f_addr[F_WSASendTo];
		return f(a, b, c, d, e, g, h, i, j);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASendTo] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

BOOL PASCAL stub_WSASetEvent(WSAEVENT a)
{
	if (g_f_addr[F_WSASetEvent])
	{
		BOOL PASCAL (* f)(WSAEVENT) = g_f_addr[F_WSASetEvent];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASetEvent] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSASetServiceA(LPWSAQUERYSETA a, WSAESETSERVICEOP b, DWORD c)
{
	if (g_f_addr[F_WSASetServiceA])
	{
		INT PASCAL (* f)(LPWSAQUERYSETA, WSAESETSERVICEOP, DWORD) = g_f_addr[F_WSASetServiceA];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASetServiceA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSASetServiceW(LPWSAQUERYSETW a, WSAESETSERVICEOP b, DWORD c)
{
	if (g_f_addr[F_WSASetServiceW])
	{
		INT PASCAL (* f)(LPWSAQUERYSETW, WSAESETSERVICEOP, DWORD) = g_f_addr[F_WSASetServiceW];
		return f(a, b, c);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASetServiceW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_WSASocketA(int a, int b, int c, LPWSAPROTOCOL_INFOA d, GROUP e, DWORD g)
{
	if (g_f_addr[F_WSASocketA])
	{
		SOCKET PASCAL (* f)(int, int, int, LPWSAPROTOCOL_INFOA, GROUP, DWORD) = g_f_addr[F_WSASocketA];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASocketA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

SOCKET PASCAL stub_WSASocketW(int a, int b, int c, LPWSAPROTOCOL_INFOW d, GROUP e, DWORD g)
{
	if (g_f_addr[F_WSASocketW])
	{
		SOCKET PASCAL (* f)(int, int, int, LPWSAPROTOCOL_INFOW, GROUP, DWORD) = g_f_addr[F_WSASocketW];
		return f(a, b, c, d, e, g);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSASocketW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAStringToAddressA(LPSTR a, INT b, LPWSAPROTOCOL_INFOA c, LPSOCKADDR d, LPINT e)
{
	if (g_f_addr[F_WSAStringToAddressA])
	{
		INT PASCAL (* f)(LPSTR, INT, LPWSAPROTOCOL_INFOA, LPSOCKADDR, LPINT) = g_f_addr[F_WSAStringToAddressA];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAStringToAddressA] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSAStringToAddressW(LPWSTR a, INT b, LPWSAPROTOCOL_INFOW c, LPSOCKADDR d, LPINT e)
{
	if (g_f_addr[F_WSAStringToAddressW])
	{
		INT PASCAL (* f)(LPWSTR, INT, LPWSAPROTOCOL_INFOW, LPSOCKADDR, LPINT) = g_f_addr[F_WSAStringToAddressW];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAStringToAddressW] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

DWORD PASCAL stub_WSAWaitForMultipleEvents(DWORD a, const WSAEVENT* b, BOOL c, DWORD d, BOOL e)
{
	if (g_f_addr[F_WSAWaitForMultipleEvents])
	{
		DWORD PASCAL (* f)(DWORD, const WSAEVENT*, BOOL, DWORD, BOOL) = g_f_addr[F_WSAWaitForMultipleEvents];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSAWaitForMultipleEvents] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCDeinstallProvider(LPGUID a, LPINT b)
{
	if (g_f_addr[F_WSCDeinstallProvider])
	{
		int PASCAL (* f)(LPGUID, LPINT) = g_f_addr[F_WSCDeinstallProvider];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCDeinstallProvider] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSCEnableNSProvider(LPGUID a, BOOL b)
{
	if (g_f_addr[F_WSCEnableNSProvider])
	{
		INT PASCAL (* f)(LPGUID, BOOL) = g_f_addr[F_WSCEnableNSProvider];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCEnableNSProvider] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCEnumProtocols(LPINT a, /*LPWSAPROTOCOL_INFOW*/void * b, LPDWORD c, LPINT d)
{
	if (g_f_addr[F_WSCEnumProtocols])
	{
		int PASCAL (* f)(LPINT, /*LPWSAPROTOCOL_INFOW*/void *, LPDWORD, LPINT) = g_f_addr[F_WSCEnumProtocols];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCEnumProtocols] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCGetProviderPath(LPGUID a, WCHAR* b, LPINT c, LPINT d)
{
	if (g_f_addr[F_WSCGetProviderPath])
	{
		int PASCAL (* f)(LPGUID, WCHAR*, LPINT, LPINT) = g_f_addr[F_WSCGetProviderPath];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCGetProviderPath] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSCInstallNameSpace(LPWSTR a, LPWSTR b, DWORD c, DWORD d, LPGUID e)
{
	if (g_f_addr[F_WSCInstallNameSpace])
	{
		INT PASCAL (* f)(LPWSTR, LPWSTR, DWORD, DWORD, LPGUID) = g_f_addr[F_WSCInstallNameSpace];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCInstallNameSpace] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCInstallProvider(LPGUID a, const WCHAR* b, const LPWSAPROTOCOL_INFOW c, DWORD d, LPINT e)
{
	if (g_f_addr[F_WSCInstallProvider])
	{
		int PASCAL (* f)(LPGUID, const WCHAR*, const LPWSAPROTOCOL_INFOW, DWORD, LPINT) = g_f_addr[F_WSCInstallProvider];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCInstallProvider] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_WSCUnInstallNameSpace(LPGUID a)
{
	if (g_f_addr[F_WSCUnInstallNameSpace])
	{
		INT PASCAL (* f)(LPGUID) = g_f_addr[F_WSCUnInstallNameSpace];
		return f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCUnInstallNameSpace] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCUpdateProvider(LPGUID a, const WCHAR* b, const LPWSAPROTOCOL_INFOW c, DWORD d, LPINT e)
{
	if (g_f_addr[F_WSCUpdateProvider])
	{
		int PASCAL (* f)(LPGUID, const WCHAR*, const LPWSAPROTOCOL_INFOW, DWORD, LPINT) = g_f_addr[F_WSCUpdateProvider];
		return f(a, b, c, d, e);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCUpdateProvider] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCWriteNameSpaceOrder(LPGUID a, DWORD b)
{
	if (g_f_addr[F_WSCWriteNameSpaceOrder])
	{
		int PASCAL (* f)(LPGUID, DWORD) = g_f_addr[F_WSCWriteNameSpaceOrder];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCWriteNameSpaceOrder] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

int PASCAL stub_WSCWriteProviderOrder(LPDWORD a, DWORD b)
{
	if (g_f_addr[F_WSCWriteProviderOrder])
	{
		int PASCAL (* f)(LPDWORD, DWORD) = g_f_addr[F_WSCWriteProviderOrder];
		return f(a, b);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[WSCWriteProviderOrder] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

VOID PASCAL stub_freeaddrinfo(/*PADDRINFOA*/void * a)
{
	if (g_f_addr[F_freeaddrinfo])
	{
		VOID PASCAL (* f)(/*PADDRINFOA*/void *) = g_f_addr[F_freeaddrinfo];
		f(a);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[freeaddrinfo] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
}

INT PASCAL stub_getaddrinfo(PCSTR a, PCSTR b, const /*ADDRINFOA*/void * c, /*PADDRINFOA*/void * d)
{
	if (g_f_addr[F_getaddrinfo])
	{
		INT PASCAL (* f)(PCSTR, PCSTR, const /*ADDRINFOA*/void *, /*PADDRINFOA*/void *) = g_f_addr[F_getaddrinfo];
		return f(a, b, c, d);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getaddrinfo] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		ExitProcess(0);
	}
	return 0;
}

INT PASCAL stub_getnameinfo(const SOCKADDR * a, /*socklen_t*/void * b, PCHAR c, DWORD d, PCHAR e, DWORD g, INT h)
{
	if (g_f_addr[F_getnameinfo])
	{
		INT PASCAL (* f)(const SOCKADDR *, /*socklen_t*/void *, PCHAR, DWORD, PCHAR, DWORD, INT) = g_f_addr[F_getnameinfo];
		return f(a, b, c, d, e, g, h);
	} else
	{
		MessageBoxA(NULL, "ERROR: FUNC[getnameinfo] NULL ADDR!", "AZIMUTH PROXYFIER", MB_OK | MB_ICONERROR | MB_APPLMODAL);
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
