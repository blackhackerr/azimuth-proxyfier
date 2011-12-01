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

#include "wsock32_base64.h"

char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char base64_index(char c)
{
	if (c == '=')
	{
		return 0;
	}
	for (size_t i = 0; i < 64; i++)
	{
		if (c == base64_chars[i])
		{
			return i;
		}
	}
	return 0xFF;
}

size_t base64_enc_size(char * in, size_t in_size)
{
	return (in_size + 2) / 3 * 4;
}

int base64_enc_block(unsigned char in[3], size_t in_size, unsigned char out[4])
{
	if ((in_size < 1) || (in_size > 3))
	{
		return 0;
	}
	out[0] = base64_chars[in[0] >> 2];
	out[1] = base64_chars[((in[0] & 0x03) << 4) | (in[1] >> 4)];
	out[2] = (in_size > 1)? base64_chars[((in[1] & 0x0F) << 2) | (in[2] >> 6)] : (unsigned char)'=';
	out[3] = (in_size > 2)? base64_chars[in[2] & 0x3F] : (unsigned char)'=';
	return 1;
}

int base64_enc(char * in, size_t in_size, char * out, size_t out_size)
{
	size_t out_need_size = base64_enc_size(in, in_size);
	if (in && in_size && out && out_size && out_need_size && (out_need_size <= out_size))
	{
		size_t block_in_size;
		while (in_size)
		{
			block_in_size = (in_size > 3)? 3 : in_size;
			base64_enc_block((unsigned char *)in, block_in_size, (unsigned char *)out);
			in += block_in_size;
			in_size -= block_in_size;
			out += 4;
		}
	}
	return 0;
}

size_t base64_dec_size(char * in, size_t in_size)
{
	if ((in_size % 4) != 0) // not base64
	{
		return 0;
	}
	size_t correction = 0;
	if (in)
	{
		if (in[in_size - 1] == '=')
		{
			correction++;
			if (in[in_size - 2] == '=')
			{
				correction++;
			}
		}
	}
	return in_size / 4 * 3 - correction;
}

size_t base64_dec_block(unsigned char in[4], unsigned char out[3])
{
	if ((base64_index((char)in[0]) == 0xFF) || (base64_index((char)in[1]) == 0xFF) || (base64_index((char)in[2]) == 0xFF) || (base64_index((char)in[3]) == 0xFF))
	{
		return 0;
	}
	size_t out_size = 1;
	out[0] = (base64_index((char)in[0]) << 2) | (base64_index((char)in[1]) >> 4);
	if (in[2] != (unsigned char)'=')
	{
		out[1] = ((base64_index((char)in[1]) << 4) | (base64_index((char)in[2]) >> 2));
		out_size++;
	}
	if (in[3] != (unsigned char)'=')
	{
		out[2] = ((base64_index((char)in[2]) << 6) | (base64_index((char)in[3]) & 0x3F));
		out_size++;
	}
	return out_size;
}

int base64_dec(char * in, size_t in_size, char * out, size_t out_size)
{
	size_t out_need_size = base64_dec_size(in, in_size);
	if (in && in_size && out && out_size && out_need_size && (out_need_size <= out_size))
	{
		size_t block_in_size;
		size_t block_out_size;
		while (in_size)
		{
			block_in_size = (in_size > 4)? 4 : in_size;
			block_out_size = base64_dec_block((unsigned char *)in, (unsigned char *)out);
			in += block_in_size;
			in_size -= block_in_size;
			out += block_out_size;
		}
	}
	return 0;
}
