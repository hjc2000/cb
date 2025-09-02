#pragma once
#include "cb/cb_define.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief cb_bitset128 的位宽。需要实现其他位宽的位集时可以复制一份代码，
/// 修改此宏。
///
/// @note 这个宏就相当于 C++ 的模板参数。
///
#define __template_cb_bitset128_bit_width ((uint32_t)128)

///
/// @brief 位集所需的字节数。
///
///
#define __cb_bitset128_byte_count ((uint32_t)((__template_cb_bitset128_bit_width / 8) + \
											  (bool)(__template_cb_bitset128_bit_width % 8)))

	///
	/// @brief 具有 128 位的位集。
	///
	///
	typedef struct cb_bitset128
	{
		uint8_t _array[__cb_bitset128_byte_count];
	} cb_bitset128;

	///
	/// @brief 初始化位集。
	///
	/// @param self
	///
	__cb_force_inline void cb_bitset128_initialize(cb_bitset128 *self)
	{
		memset(self->_array, 0, sizeof(self->_array));
	}

	///
	/// @brief 读取位集的一个位。
	///
	/// @param self
	/// @param bit_index
	/// @return
	///
	__cb_force_inline bool cb_bitset128_read_bit(cb_bitset128 const *self, uint8_t bit_index)
	{
		if (bit_index >= __template_cb_bitset128_bit_width)
		{
			return false;
		}

		int32_t byte_index = bit_index / 8;
		int32_t bit_index_within_byte = bit_index % 8;
		uint8_t byte = self->_array[byte_index];
		return (byte & ((uint8_t)(1) << bit_index_within_byte)) != 0;
	}

	///
	/// @brief 写位集的一个位。
	///
	/// @param self
	/// @param bit_index
	/// @param value
	///
	__cb_force_inline void cb_bitset128_write_bit(cb_bitset128 *self, uint8_t bit_index, bool value)
	{
		if (bit_index >= __template_cb_bitset128_bit_width)
		{
			return;
		}

		int32_t byte_index = bit_index / 8;
		int32_t bit_index_in_byte = bit_index % 8;
		uint8_t byte = self->_array[byte_index];
		if (value)
		{
			byte |= ((uint8_t)(1) << bit_index_in_byte);
		}
		else
		{
			byte &= ~((uint8_t)(1) << bit_index_in_byte);
		}

		self->_array[byte_index] = byte;
	}

#ifdef __cplusplus
}
#endif
