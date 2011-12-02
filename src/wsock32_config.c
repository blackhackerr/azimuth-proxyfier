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
 
#include "wsock32_config.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

char g_ini_path[MAX_PATH] = {0};
char g_hosts_path[MAX_PATH] = {0};

int g_proxy_use = 0;
char g_proxy_addr[MAX_PATH] = {0};
unsigned short g_proxy_port = 0;
int g_proxy_useauth = 0;
int g_proxy_usentlm = 0;
char g_proxy_user[MAX_PATH] = {0};
char g_proxy_pass[MAX_PATH] = {0};
int g_proxy_usehosts = 0;
int g_proxy_usens = 0;

void conf_init(void)
{
	g_proxy_use = GetPrivateProfileInt("proxy", "use", 0, g_ini_path);
	GetPrivateProfileString("proxy", "addr", "127.0.0.1", g_proxy_addr, MAX_PATH - 1, g_ini_path);
	g_proxy_port = (short)GetPrivateProfileInt("proxy", "port", 3128, g_ini_path);
	g_proxy_useauth = GetPrivateProfileInt("proxy", "auth", 0, g_ini_path);
	g_proxy_usentlm = GetPrivateProfileInt("proxy", "ntlm", 0, g_ini_path);
	GetPrivateProfileString("proxy", "user", "guest", g_proxy_user, MAX_PATH - 1, g_ini_path);
	GetPrivateProfileString("proxy", "pass", "guest", g_proxy_pass, MAX_PATH - 1, g_ini_path);
	g_proxy_usehosts = GetPrivateProfileInt("proxy", "hosts", 0, g_ini_path);
	g_proxy_usens = GetPrivateProfileInt("proxy", "ns", 0, g_ini_path);
}

void conf_deinit(void)
{
}
