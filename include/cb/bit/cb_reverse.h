#pragma once
#include "cb/define.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	///
	/// @brief 反转字节数组
	///
	/// @param array
	///
	/// @param size
	///
	void cb_reverse_byte_array(uint8_t *array, int32_t size);

	///
	/// @brief 将字节数组中的字节以每个单元为单位，在单元内进行字节序反转。
	///
	/// @param array 字节数组。
	///
	/// @param element_size 每个单元的大小。
	///
	/// @param element_count 单元的个数。
	///
	__cb_force_inline void cb_reverse_byte_array_per_element(uint8_t *array,
															 int32_t element_size,
															 int32_t element_count)
	{
		if (element_size <= 1)
		{
			// 每个单元的尺寸小于等于 0 是非法的
			// 每个单元的尺寸等于 1 时翻转没有意义。
			return;
		}

		for (int32_t i = 0; i < element_count; i++)
		{
			cb_reverse_byte_array(array + element_size * i, element_size);
		}
	}

#ifdef __cplusplus
}
#endif
