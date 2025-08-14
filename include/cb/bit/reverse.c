#include "reverse.h" // IWYU pragma: keep

void cb_reverse_byte_array(uint8_t *array, int32_t size)
{
	if (size <= 1)
	{
		return;
	}

	for (int32_t i = 0; i < size / 2; i++)
	{
		// 交换数组中的元素
		uint8_t temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
}
