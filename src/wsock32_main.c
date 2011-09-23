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
#include <stdio.h>
#include <string.h>

#ifdef WS2
#include "ws2_32_funcs.h"
#else
#include "wsock32_funcs.h"
#endif
#include "wsock32_hostbyname.h"
#include "wsock32_config.h"

HMODULE g_wsock32orig = NULL;
char g_system32_path[MAX_PATH] = {0};
char g_wsock32orig_path[MAX_PATH] = {0};

BOOL APIENTRY DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
			// get system path
			if (GetSystemDirectoryA(g_system32_path, MAX_PATH - 1))
			{
#ifdef WS2
				sprintf(g_wsock32orig_path, "%s\\ws2_32.dll", g_system32_path);
#else
				sprintf(g_wsock32orig_path, "%s\\wsock32.dll", g_system32_path);
#endif
			}
			// load original library
			if (!g_wsock32orig && strlen(g_wsock32orig_path))
			{
				g_wsock32orig = LoadLibraryA(g_wsock32orig_path);
			}
			// get functions addr
			if (g_wsock32orig)
			{
				for (size_t i = 0; i < F_COUNT; i++)
				{
					g_f_addr[i] = (void *)GetProcAddress(g_wsock32orig, g_f_name[i]);
				}
			} else
			{
				for (size_t i = 0; i < F_COUNT; i++)
				{
					g_f_addr[i] = NULL;
				}
			}
			if (GetModuleFileName(hInstDLL, g_ini_path, MAX_PATH - 1))
			{
				size_t ini_path_size = strlen(g_ini_path);
				while (ini_path_size >= 0)
				{
					if (g_ini_path[ini_path_size] == '\\')
					{
						ini_path_size++;
						break;
					}
					ini_path_size--;
				}
				g_ini_path[ini_path_size] = '\0';
				strcat(g_ini_path, "azimuth.conf");
			}
			conf_init();
			hbn_init();
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:

			// free original library
			if (g_wsock32orig)
			{
				FreeLibrary(g_wsock32orig);
				g_wsock32orig = NULL;
			}
			hbn_deinit();
			conf_deinit();
            break;
    }
    return TRUE;
}
