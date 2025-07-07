#pragma once
#include "cb/define.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	///
	/// @brief 计数器。
	///
	///
	typedef struct cb_counter_32
	{
		uint32_t _max_value;
		uint32_t _count;
	} cb_counter_32;

	///
	/// @brief 初始化计数器。
	///
	/// @param self
	/// @param current_value 计数器当前值。
	/// @param max_value 计数器允许的最大值。
	/// @return
	///
	void cb_counter_32_initialize(cb_counter_32 *self,
								  uint32_t current_value,
								  uint32_t max_value);

	__cb_force_inline void cb_counter_32_increment(cb_counter_32 *self)
	{
	}

	__cb_force_inline void cb_counter_32_decrement(cb_counter_32 *self)
	{
	}

	uint32_t cb_counter_32_add(cb_counter_32 *self, uint32_t value);

	uint32_t cb_counter_32_subtract(cb_counter_32 *self, uint32_t value);

#ifdef __cplusplus
}
#endif
