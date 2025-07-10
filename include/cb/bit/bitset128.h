#pragma once
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cb_bitset128
	{
		uint8_t _array[128 / 8];
	} cb_bitset128;

	bool cb_bitset128_read_bit(cb_bitset128 const *self, uint8_t bit_index);

	void cb_bitset128_write_bit(cb_bitset128 *self, uint8_t bit_index, bool value);

#ifdef __cplusplus
}
#endif
