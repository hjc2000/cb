#include "auto_bit_converter.h" // IWYU pragma: keep
#include "cb/bit_converter.h"
#include "cb/reverse.h"
#include "endian.h"

void cb_auto_bit_converter_initialize(cb_auto_bit_converter *self, cb_endian_enum remote_endian)
{
	self->_should_reverse = cb_native_endian != remote_endian;
}

/* #region 转数字 */

uint16_t cb_auto_bit_converter_to_uint16(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	uint16_t ret = cb_bit_converter_byte_array_to_uint16(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

int16_t cb_auto_bit_converter_to_int16(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	int16_t ret = cb_bit_converter_byte_array_to_int16(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

uint32_t cb_auto_bit_converter_to_uint32(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	uint32_t ret = cb_bit_converter_byte_array_to_uint32(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

int32_t cb_auto_bit_converter_to_int32(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	int32_t ret = cb_bit_converter_byte_array_to_int32(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

uint64_t cb_auto_bit_converter_to_uint64(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	uint64_t ret = cb_bit_converter_byte_array_to_uint64(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

int64_t cb_auto_bit_converter_to_int64(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	int64_t ret = cb_bit_converter_byte_array_to_int64(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

float cb_auto_bit_converter_to_float(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	float ret = cb_bit_converter_byte_array_to_float(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

double cb_auto_bit_converter_to_double(cb_auto_bit_converter *self, uint8_t const *buffer, int32_t offset)
{
	double ret = cb_bit_converter_byte_array_to_double(buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
	}

	return ret;
}

/* #endregion */

/* #region 转字节数组 */

void cb_auto_bit_converter_get_bytes_from_uint16(cb_auto_bit_converter *self, uint16_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_uint16(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int16(cb_auto_bit_converter *self, int16_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_int16(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_uint32(cb_auto_bit_converter *self, uint32_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_uint32(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int32(cb_auto_bit_converter *self, int32_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_int32(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_uint64(cb_auto_bit_converter *self, uint64_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_uint64(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_int64(cb_auto_bit_converter *self, int64_t value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_int64(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_float(cb_auto_bit_converter *self, float value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_float(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

void cb_auto_bit_converter_get_bytes_from_double(cb_auto_bit_converter *self, double value, uint8_t *out_buffer, int32_t offset)
{
	cb_bit_converter_get_bytes_from_double(value, out_buffer, offset);
	if (self->_should_reverse)
	{
		cb_reverse_byte_array(out_buffer + offset, sizeof(value));
	}
}

/* #endregion */
