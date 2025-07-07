#pragma once
#include "bit_converter.h"
#include "cb/bit/endian.h"
#include "cb/define.h"
#include "reverse.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct auto_bit_converter
	{
		cb_endian_enum _remote_endian;
	} auto_bit_converter;

	__cb_force_inline void cb_auto_bit_converter_initialize(auto_bit_converter *self,
															cb_endian_enum remote_endian)
	{
		self->_remote_endian = remote_endian;
	}

	__cb_force_inline bool cb_auto_bit_converter_should_reverse(auto_bit_converter *self)
	{
		if (cb_native_endian() == self->_remote_endian)
		{
			return false;
		}

		return true;
	}

	__cb_force_inline uint16_t cb_auto_bit_converter_byte_array_to_uint16(auto_bit_converter *self,
																		  uint8_t const *buffer)
	{
		uint16_t ret = cb_byte_array_to_uint16(buffer);
		if (cb_auto_bit_converter_should_reverse(self))
		{
			cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
		}

		return ret;
	}

	__cb_force_inline int16_t cb_auto_bit_converter_byte_array_to_int16(auto_bit_converter *self,
																		uint8_t const *buffer)
	{
		int16_t ret = cb_byte_array_to_int16(buffer);
		if (cb_auto_bit_converter_should_reverse(self))
		{
			cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
		}

		return ret;
	}

	__cb_force_inline uint32_t cb_auto_bit_converter_byte_array_to_uint32(auto_bit_converter *self,
																		  uint8_t const *buffer)
	{
		uint32_t ret = cb_byte_array_to_uint32(buffer);
		if (cb_auto_bit_converter_should_reverse(self))
		{
			cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
		}

		return ret;
	}

	__cb_force_inline int32_t cb_auto_bit_converter_byte_array_to_int32(auto_bit_converter *self,
																		uint8_t const *buffer)
	{
		int32_t ret = cb_byte_array_to_int32(buffer);
		if (cb_auto_bit_converter_should_reverse(self))
		{
			cb_reverse_byte_array((uint8_t *)(&ret), sizeof(ret));
		}

		return ret;
	}

#ifdef __cplusplus
}
#endif
