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

#include "wsock32_httpparser.h"
#include <stdlib.h>
#include <string.h>

#define STRICMP _stricmp

typedef struct HTTP_ANSWER_HEAD
{
	char * m_protocol;
	char * m_version;
	char * m_code;
	char * m_reason;
} HTTP_ANSWER_HEAD;

typedef struct HTTP_ANSWER_PARAM_NODE HTTP_ANSWER_PARAM_NODE;
struct HTTP_ANSWER_PARAM_NODE
{
	char * m_key;
	char * m_value;
	HTTP_ANSWER_PARAM_NODE * m_next;
};

struct HTTP_ANSWER
{
	char * m_data;
	HTTP_ANSWER_HEAD * m_head;
	HTTP_ANSWER_PARAM_NODE * m_param;
};

char * _removespacepreffix(char * s)
{
	if (s)
	{
		size_t s_len = strlen(s);
		size_t i = 0;
		while (i <= s_len)
		{
			if ((s[i] != ' ') || (s[i] == '\0'))
			{
				if (i > 0)
				{
					for (size_t j = 0; j < s_len + 1 - i; j++)
					{
						s[j] = s[j + i];
					}
				}
				break;
			}
			i++;
		}
	}
	return s;
}

char * _removespacesuffix(char * s)
{
	if (s)
	{
		size_t s_len = strlen(s);
		while (s_len > 0)
		{
			if (s[s_len - 1] != ' ')
			{
				break;
			}
			s_len--;
		}
		s[s_len] = '\0';
	}
	return s;
}

HTTP_ANSWER * hp_answer_parse(char * answer_s)
{
	HTTP_ANSWER * result = (HTTP_ANSWER *)malloc(sizeof(HTTP_ANSWER));
	if (result)
	{
		memset(result, 0, sizeof(HTTP_ANSWER));
		if (answer_s)
		{
			size_t answer_s_len = strlen(answer_s);
			result->m_data = (char *)malloc(answer_s_len + 1);
			if (result->m_data)
			{
				memcpy(result->m_data, answer_s, answer_s_len + 1);
			}
		}
		if (result->m_data)
		{
			int head = 1;
			// tokenize data
			char * token = strtok(result->m_data, "\r\n");
			while (token)
			{
				if (head)
				{
					result->m_head = (HTTP_ANSWER_HEAD *)malloc(sizeof(HTTP_ANSWER_HEAD));
					if (result->m_head)
					{
						memset(result->m_head, 0, sizeof(HTTP_ANSWER_HEAD));
						result->m_head->m_protocol = token;
					}
					head = 0;
				} else
				{
					HTTP_ANSWER_PARAM_NODE * node = (HTTP_ANSWER_PARAM_NODE *)malloc(sizeof(HTTP_ANSWER_PARAM_NODE));
					if (node)
					{
						memset(node, 0, sizeof(HTTP_ANSWER_PARAM_NODE));
						node->m_key = token;
						node->m_next = result->m_param;
						result->m_param = node;
					}
				}
				token = strtok(NULL, "\r\n");
			}
			// tokenize head
			if (result->m_head && result->m_head->m_protocol)
			{
				token = strtok(result->m_head->m_protocol, " /");
				result->m_head->m_protocol = NULL;
				while (token)
				{
					if (!result->m_head->m_protocol)
					{
						result->m_head->m_protocol = token;
					} else
					if (!result->m_head->m_version)
					{
						result->m_head->m_version = token;
					} else
					if (!result->m_head->m_code)
					{
						result->m_head->m_code = token;
					} else
					if (!result->m_head->m_reason)
					{
						result->m_head->m_reason = token;
						break; // last
					}
					token = strtok(NULL, " /");
				}
			}
			// tokenize param
			HTTP_ANSWER_PARAM_NODE * node = result->m_param;
			while (node)
			{
				if (node->m_key)
				{
					token = strtok(node->m_key, ":");
					node->m_key = NULL;
					while (token)
					{
						if (!node->m_key)
						{
							node->m_key = token;
							_removespacepreffix(node->m_key);
							_removespacesuffix(node->m_key);
						} else
						if (!node->m_value)
						{
							node->m_value = token;
							_removespacepreffix(node->m_value);
							_removespacesuffix(node->m_value);
							break; // last
						}
						token = strtok(NULL, ":");
					}
				}
				node = node->m_next;
			}
		}
	}
	return result;
}

void hp_answer_delete(HTTP_ANSWER * answer)
{
	if (answer)
	{
		if (answer->m_data)
		{
			free(answer->m_data);
		}
		if (answer->m_head)
		{
			free(answer->m_head);
		}
		HTTP_ANSWER_PARAM_NODE * node = answer->m_param;
		while (node)
		{
			answer->m_param = node->m_next;
			free(node);
			node = answer->m_param;
		}
		free(answer);
	}
}

HTTP_ANSWER_CODE hp_answer_getcode(HTTP_ANSWER * answer)
{
	HTTP_ANSWER_CODE result = HTTP_INVALID;
	if (answer && answer->m_head && answer->m_head->m_code)
	{
		result = (HTTP_ANSWER_CODE)atoi(answer->m_head->m_code);
	}
	return result;
}

char * hp_answer_getvalueforkey(HTTP_ANSWER * answer, char * key)
{
	char * result = NULL;
	if (answer && key)
	{
		HTTP_ANSWER_PARAM_NODE * node = answer->m_param;
		while (node)
		{
			if (node->m_key && !STRICMP(node->m_key, key))
			{
				result = node->m_value;
				break;
			}
			node = node->m_next;
		}
	}
	return result;
}

int hp_answer_iscode_info(HTTP_ANSWER_CODE code)
{
	if ((code >= 100) && (code < 200))
	{
		return 1;
	}
	return 0;
}

int hp_answer_iscode_success(HTTP_ANSWER_CODE code)
{
	if ((code >= 200) && (code < 300))
	{
		return 1;
	}
	return 0;
}

int hp_answer_iscode_redir(HTTP_ANSWER_CODE code)
{
	if ((code >= 300) && (code < 400))
	{
		return 1;
	}
	return 0;
}

int hp_answer_iscode_cerror(HTTP_ANSWER_CODE code)
{
	if ((code >= 400) && (code < 500))
	{
		return 1;
	}
	return 0;
}

int hp_answer_iscode_serror(HTTP_ANSWER_CODE code)
{
	if ((code >= 500) && (code < 600))
	{
		return 1;
	}
	return 0;
}
