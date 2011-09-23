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

#include "wsock32_fifobuff.h"

#include <string.h>

struct FIFOBUFF
{
	char * m_buff;
	size_t m_buff_size_alloc;
	size_t m_in_offset;
	size_t m_out_offset;
};

FIFOBUFF * fb_new(size_t start_size)
{
	FIFOBUFF * result = (FIFOBUFF *)malloc(sizeof(FIFOBUFF));
	if (result)
	{
		memset(result, 0, sizeof(FIFOBUFF));
		size_t need_inc = (start_size > 0? start_size - 1 : 0) / BUFFFIFO_STARTSIZE + 1;
		result->m_buff_size_alloc = need_inc * BUFFFIFO_STARTSIZE;
		result->m_buff = (char *)malloc(result->m_buff_size_alloc);
		if (!result->m_buff)
		{
			free(result);
			result = NULL;
		}
	}
	return result;
}

void fb_delete(FIFOBUFF * buff)
{
	if (buff)
	{
		if (buff->m_buff)
		{
			free(buff->m_buff);
		}
		free(buff);
	}
}

size_t fb_size(FIFOBUFF * buff)
{
	if (buff)
	{
		return buff->m_in_offset - buff->m_out_offset;
	}
	return 0;
}

int fb_push(FIFOBUFF * buff, void * data, size_t data_size)
{
	int result = 0;
	if (buff && buff->m_buff && data && data_size)
	{
		size_t need_size = buff->m_in_offset + data_size; 
		if (need_size > buff->m_buff_size_alloc)
		{
			// need increase buff
			size_t need_inc = (need_size > 0? need_size - 1 : 0) / BUFFFIFO_STARTSIZE + 1;
			buff->m_buff_size_alloc += need_inc * BUFFFIFO_STARTSIZE;
			buff->m_buff = (char *)realloc(buff->m_buff, buff->m_buff_size_alloc);
		}
		if (buff->m_buff)
		{
			memcpy(buff->m_buff + buff->m_in_offset, data, data_size);
			buff->m_in_offset += data_size;
			result = 1;
		}
	}
	return result;
}

int fb_pushzero(FIFOBUFF * buff, size_t zero_size)
{
	int result = 0;
	if (buff && buff->m_buff && zero_size)
	{
		size_t need_size = buff->m_in_offset + zero_size; 
		if (need_size > buff->m_buff_size_alloc)
		{
			// need increase buff
			size_t need_inc = (need_size > 0? need_size - 1 : 0) / BUFFFIFO_STARTSIZE + 1;
			buff->m_buff_size_alloc += need_inc * BUFFFIFO_STARTSIZE;
			buff->m_buff = (char *)realloc(buff->m_buff, buff->m_buff_size_alloc);
		}
		if (buff->m_buff)
		{
			memset(buff->m_buff + buff->m_in_offset, 0, zero_size);
			buff->m_in_offset += zero_size;
			result = 1;
		}
	}
	return result;
}

int fb_pop(FIFOBUFF * buff, void * data, size_t data_size)
{
	int result = 0;
	if (buff && buff->m_buff && data_size && (data_size <= fb_size(buff)))
	{
		if (data)
		{
			memcpy(data, buff->m_buff + buff->m_out_offset, data_size);
		}
		buff->m_out_offset += data_size;
		if (buff->m_out_offset)
		{
			size_t curr_size = fb_size(buff);
			if (curr_size)
			{
				// need move data to start buff
				for (size_t i = 0; i < curr_size; i++)
				{
					buff->m_buff[i] = buff->m_buff[i + buff->m_out_offset];
				}
			}
			buff->m_out_offset = 0;
			buff->m_in_offset = curr_size;
		}
	}
	return result;
}

int fb_clear(FIFOBUFF * buff)
{
	return fb_popsize(buff, fb_size(buff));
}

void * fb_getdataptr(FIFOBUFF * buff)
{
	void * result = NULL;
	if (buff && buff->m_buff && fb_size(buff))
	{
		result = buff->m_buff + buff->m_out_offset;
	}
	return result;
}

int fb_popsize(FIFOBUFF * buff, size_t data_size)
{
	return fb_pop(buff, NULL, data_size);
}
