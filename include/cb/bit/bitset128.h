#pragma once
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	///
	/// @brief 具有 128 位的位集。
	///
	///
	typedef struct cb_bitset128
	{
		uint8_t _array[128 / 8];
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
