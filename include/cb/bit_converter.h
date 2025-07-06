#pragma once
#include "define.h"
#include <stdint.h>
#include <string.h>

/* #region 转数字 */

__force_inline uint16_t cb_byte_array_to_uint16(uint8_t const *buffer, int32_t offset)
{
	uint16_t ret;
	memcpy((uint8_t *)(&ret), buffer + offset, sizeof(ret));
	return ret;
}

__force_inline int16_t cb_byte_array_to_int16(uint8_t const *buffer, int32_t offset)
{
	int16_t ret;
	memcpy((uint8_t *)(&ret), buffer + offset, sizeof(ret));
	return ret;
}

__force_inline uint16_t cb_2_byte_to_uint16(uint8_t high, uint8_t low)
{
	return ((uint16_t)high << 8) | low;
}

__force_inline uint32_t cb_bit_converter_byte_array_to_uint32(uint8_t const *buffer, int32_t offset)
{
	uint32_t ret;
	memcpy((uint8_t *)(&ret), buffer + offset, sizeof(ret));
	return ret;
}

int32_t cb_bit_converter_byte_array_to_int32(uint8_t const *buffer, int32_t offset);

uint32_t cb_bit_converter_2_uint16_to_uint32(uint16_t high, uint16_t low);

uint32_t cb_bit_converter_4_byte_to_uint32(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0);

uint64_t cb_bit_converter_byte_array_to_uint64(uint8_t const *buffer, int32_t offset);

int64_t cb_bit_converter_byte_array_to_int64(uint8_t const *buffer, int32_t offset);

float cb_bit_converter_byte_array_to_float(uint8_t const *buffer, int32_t offset);

double cb_bit_converter_byte_array_to_double(uint8_t const *buffer, int32_t offset);

/* #endregion */

/* #region 转字节数组 */

void cb_bit_converter_get_bytes_from_uint16(uint16_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_int16(int16_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_uint32(uint32_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_int32(int32_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_uint64(uint64_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_int64(int64_t value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_float(float value, uint8_t *out_buffer, int32_t offset);

void cb_bit_converter_get_bytes_from_double(double value, uint8_t *out_buffer, int32_t offset);

/* #endregion */
