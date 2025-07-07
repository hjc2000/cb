#pragma once
#include "cb/define.h"
#include <stdbool.h>
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

	///
	/// @brief 将计数器的值增加指定的值。
	///
	/// @note 溢出会发生环绕。
	///
	/// @param self
	/// @param value
	///
	void cb_counter_32_add(cb_counter_32 *self, uint32_t value);

	///
	/// @brief 将计数器的值减少指定的值。
	///
	/// @note 溢出会发生环绕。
	///
	/// @param self
	/// @param value
	///
	void cb_counter_32_subtract(cb_counter_32 *self, uint32_t value);

	///
	/// @brief 将计数器的值递增 1.
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_32_increment(cb_counter_32 *self)
	{
		cb_counter_32_add(self, 1);
	}

	///
	/// @brief 将计数器的值递减 1.
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_32_decrement(cb_counter_32 *self)
	{
		cb_counter_32_subtract(self, 1);
	}

	///
	/// @brief 重置计数器。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_32_reset(cb_counter_32 *self)
	{
		self->_count = 0;
	}

	///
	/// @brief 获取计数器的当前值。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline uint32_t cb_counter_32_current_value(cb_counter_32 *self)
	{
		return self->_count;
	}

	///
	/// @brief 设置计数器的当前值。
	///
	/// @note 溢出会发生环绕。
	///
	/// @param self
	/// @param value
	/// @return
	///
	__cb_force_inline void cb_counter_32_set_current_value(cb_counter_32 *self, uint32_t value)
	{
		self->_count = 0;
		cb_counter_32_add(self, value);
	}

	/* #region 比较大小 */

	///
	/// @brief self 是否等于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_32_equal(cb_counter_32 *self, cb_counter_32 *other)
	{
		return self->_count == other->_count;
	}

	///
	/// @brief self 是否大于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_32_greater_than(cb_counter_32 *self, cb_counter_32 *other)
	{
		return self->_count > other->_count;
	}

	///
	/// @brief self 是否小于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_32_less_than(cb_counter_32 *self, cb_counter_32 *other)
	{
		return self->_count < other->_count;
	}

	///
	/// @brief self 是否大于等于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_32_greater_than_or_equal(cb_counter_32 *self, cb_counter_32 *other)
	{
		return self->_count >= other->_count;
	}

	///
	/// @brief self 是否小于等于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_32_less_than_or_equal(cb_counter_32 *self, cb_counter_32 *other)
	{
		return self->_count <= other->_count;
	}

	/* #endregion */

#ifdef __cplusplus
}
#endif
