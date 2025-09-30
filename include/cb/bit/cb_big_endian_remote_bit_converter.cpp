#include "cb_big_endian_remote_bit_converter.h" // IWYU pragma: keep
#include "cb/bit/cb_auto_bit_converter.h"

uint16_t cb_big_endian_remote_bit_converter_byte_array_to_uint16(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_uint16(&converter, buffer);
}

int16_t cb_big_endian_remote_bit_converter_byte_array_to_int16(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_int16(&converter, buffer);
}

uint32_t cb_big_endian_remote_bit_converter_byte_array_to_uint32(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_uint32(&converter, buffer);
}

int32_t cb_big_endian_remote_bit_converter_byte_array_to_int32(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_int32(&converter, buffer);
}

uint64_t cb_big_endian_remote_bit_converter_byte_array_to_uint64(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_uint64(&converter, buffer);
}

int64_t cb_big_endian_remote_bit_converter_byte_array_to_int64(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_int64(&converter, buffer);
}

float cb_big_endian_remote_bit_converter_byte_array_to_float(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_float(&converter, buffer);
}

double cb_big_endian_remote_bit_converter_byte_array_to_double(
	uint8_t const *buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	return cb_auto_bit_converter_byte_array_to_double(&converter, buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_uint16(
	uint16_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_uint16(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_int16(
	int16_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_int16(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_uint32(
	uint32_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_uint32(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_int32(
	int32_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_int32(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_uint64(
	uint64_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_uint64(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_int64(
	int64_t value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_int64(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_float(
	float value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_float(&converter, value, out_buffer);
}

void cb_big_endian_remote_bit_converter_get_bytes_from_double(
	double value,
	uint8_t *out_buffer)
{
	cb_auto_bit_converter converter;
	cb_auto_bit_converter_initialize(&converter, cb_endian_big_endian);
	cb_auto_bit_converter_get_bytes_from_double(&converter, value, out_buffer);
}
