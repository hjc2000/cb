#include "cb_bit_converter.h" // IWYU pragma: keep
#include <algorithm>
#include <cstdint>

uint16_t cb_bit_converter_byte_array_to_uint16(uint8_t const *buffer)
{
	uint16_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

int16_t cb_bit_converter_byte_array_to_int16(uint8_t const *buffer)
{
	int16_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

uint16_t cb_bit_converter_2_byte_to_uint16(uint8_t high, uint8_t low)
{
	return ((uint16_t)high << 8) | low;
}

uint32_t cb_bit_converter_byte_array_to_uint32(uint8_t const *buffer)
{
	uint32_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

int32_t cb_bit_converter_byte_array_to_int32(uint8_t const *buffer)
{
	int32_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

uint32_t cb_bit_converter_2_uint16_to_uint32(uint16_t high, uint16_t low)
{
	return ((uint32_t)high << 16) | low;
}

uint32_t cb_bit_converter_4_byte_to_uint32(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0)
{
	uint16_t high = cb_bit_converter_2_byte_to_uint16(b3, b2);
	uint16_t low = cb_bit_converter_2_byte_to_uint16(b1, b0);
	return cb_bit_converter_2_uint16_to_uint32(high, low);
}

uint64_t cb_bit_converter_byte_array_to_uint64(uint8_t const *buffer)
{
	uint64_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

int64_t cb_bit_converter_byte_array_to_int64(uint8_t const *buffer)
{
	int64_t ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

float cb_bit_converter_byte_array_to_float(uint8_t const *buffer)
{
	float ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

double cb_bit_converter_byte_array_to_double(uint8_t const *buffer)
{
	double ret;

	std::copy(buffer,
			  buffer + sizeof(ret),
			  reinterpret_cast<uint8_t *>(&ret));

	return ret;
}

void cb_bit_converter_get_bytes_from_uint16(uint16_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_int16(int16_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_uint32(uint32_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_int32(int32_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_uint64(uint64_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_int64(int64_t value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_float(float value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}

void cb_bit_converter_get_bytes_from_double(double value, uint8_t *out_buffer)
{
	uint8_t const *buffer = (uint8_t const *)(&value);
	std::copy(buffer, buffer + sizeof(value), out_buffer);
}
