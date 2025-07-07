#include "bit_converter.h" // IWYU pragma: keep
#include <stdint.h>
#include <string.h>

/* #region 转字节数组 */

void cb_bit_converter_get_bytes_from_int16(int16_t value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_uint32(uint32_t value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_int32(int32_t value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_uint64(uint64_t value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_int64(int64_t value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_float(float value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

void cb_bit_converter_get_bytes_from_double(double value, uint8_t *out_buffer, int32_t offset)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	memcpy(out_buffer + offset, buffer, sizeof(value));
}

/* #endregion */
