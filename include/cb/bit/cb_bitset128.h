#pragma once
#include <stdbool.h>
#include <stdint.h>

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
	void cb_bitset128_initialize(cb_bitset128 *self);

	///
	/// @brief 读取位集的一个位。
	///
	/// @param self
	/// @param bit_index
	/// @return
	///
	bool cb_bitset128_read_bit(cb_bitset128 const *self, uint8_t bit_index);

	///
	/// @brief 写位集的一个位。
	///
	/// @param self
	/// @param bit_index
	/// @param value
	///
	void cb_bitset128_write_bit(cb_bitset128 *self, uint8_t bit_index, bool value);

#ifdef __cplusplus
}
#endif
