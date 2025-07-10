#include "bitset128.h" // IWYU pragma: keep

bool cb_bitset128_read_bit(cb_bitset128 const *self, uint8_t bit_index)
{
	if (bit_index >= 128)
	{
		return false;
	}

	int32_t byte_index = bit_index / 8;
	int32_t bit_index_in_byte = bit_index % 8;
	uint8_t byte = self->_array[byte_index];
	return (byte & ((uint8_t)(1) << bit_index_in_byte)) != 0;
}

void cb_bitset128_write_bit(cb_bitset128 *self, uint8_t bit_index, bool value)
{
	if (bit_index >= 128)
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
