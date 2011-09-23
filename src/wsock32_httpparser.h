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

#ifndef WSOCK32_HTTPPARSER_H
#define WSOCK32_HTTPPARSER_H

typedef enum
{
	HTTP_NONE = -1,
	HTTP_INVALID = 0,
	// success
	HTTP_OK = 200,
	// cerror
	HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
} HTTP_ANSWER_CODE;

typedef struct HTTP_ANSWER HTTP_ANSWER;

HTTP_ANSWER * hp_answer_parse(char * answer_s);
void hp_answer_delete(HTTP_ANSWER * answer);

HTTP_ANSWER_CODE hp_answer_getcode(HTTP_ANSWER * answer);
char * hp_answer_getvalueforkey(HTTP_ANSWER * answer, char * key);

int hp_answer_iscode_info(HTTP_ANSWER_CODE code);
int hp_answer_iscode_success(HTTP_ANSWER_CODE code);
int hp_answer_iscode_redir(HTTP_ANSWER_CODE code);
int hp_answer_iscode_cerror(HTTP_ANSWER_CODE code);
int hp_answer_iscode_serror(HTTP_ANSWER_CODE code);

#endif // WSOCK32_HTTPPARSER_H

