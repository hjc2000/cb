#include "cb_auto_bit_converter.h" // IWYU pragma: keep
#include "cb_bit_converter.h"
#include <algorithm>
#include <cstdint>

bool __cb_auto_bit_converter_should_reverse__(cb_auto_bit_converter *self)
{
	if (cb_endian_native_endian() == self->_remote_endian)
	{
		return false;
	}

	return true;
}

void cb_auto_bit_converter_initialize(cb_auto_bit_converter *self,
									  cb_endian_enum remote_endian)
{
	self->_remote_endian = remote_endian;
}

uint16_t cb_auto_bit_converter_byte_array_to_uint16(cb_auto_bit_converter *self,
													uint8_t const *buffer)
{
	uint16_t ret = cb_bit_converter_byte_array_to_uint16(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

int16_t cb_auto_bit_converter_byte_array_to_int16(cb_auto_bit_converter *self,
												  uint8_t const *buffer)
{
	int16_t ret = cb_bit_converter_byte_array_to_int16(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

uint32_t cb_auto_bit_converter_byte_array_to_uint32(cb_auto_bit_converter *self,
													uint8_t const *buffer)
{
	uint32_t ret = cb_bit_converter_byte_array_to_uint32(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

int32_t cb_auto_bit_converter_byte_array_to_int32(cb_auto_bit_converter *self,
												  uint8_t const *buffer)
{
	int32_t ret = cb_bit_converter_byte_array_to_int32(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

uint64_t cb_auto_bit_converter_byte_array_to_uint64(cb_auto_bit_converter *self,
													uint8_t const *buffer)
{
	uint64_t ret = cb_bit_converter_byte_array_to_uint64(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

int64_t cb_auto_bit_converter_byte_array_to_int64(cb_auto_bit_converter *self,
												  uint8_t const *buffer)
{
	int64_t ret = cb_bit_converter_byte_array_to_int64(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

float cb_auto_bit_converter_byte_array_to_float(cb_auto_bit_converter *self,
												uint8_t const *buffer)
{
	float ret = cb_bit_converter_byte_array_to_float(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

double cb_auto_bit_converter_byte_array_to_double(cb_auto_bit_converter *self,
												  uint8_t const *buffer)
{
	double ret = cb_bit_converter_byte_array_to_double(buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(reinterpret_cast<uint8_t *>(&ret),
					 reinterpret_cast<uint8_t *>(&ret) + sizeof(ret));
	}

	return ret;
}

void cb_auto_bit_converter_get_bytes_from_uint16(cb_auto_bit_converter *self,
												 uint16_t value,
												 uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_uint16(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int16(cb_auto_bit_converter *self,
												int16_t value,
												uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_int16(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_uint32(cb_auto_bit_converter *self,
												 uint32_t value,
												 uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_uint32(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int32(cb_auto_bit_converter *self,
												int32_t value,
												uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_int32(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_uint64(cb_auto_bit_converter *self,
												 uint64_t value,
												 uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_uint64(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int64(cb_auto_bit_converter *self,
												int64_t value,
												uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_int64(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_float(cb_auto_bit_converter *self,
												float value,
												uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_float(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_double(cb_auto_bit_converter *self,
												 double value,
												 uint8_t *out_buffer)
{
	cb_bit_converter_get_bytes_from_double(value, out_buffer);
	if (__cb_auto_bit_converter_should_reverse__(self))
	{
		std::reverse(out_buffer,
					 out_buffer + sizeof(value));
	}
}
