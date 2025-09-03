#pragma once
#include "cb/cb_define.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __template_cb_counter_type
	#define __template_cb_counter_type uint32_t
#endif

	///
	/// @brief 计数器。
	///
	///
	typedef struct cb_counter
	{
		__template_cb_counter_type _max_value;
		__template_cb_counter_type _count;
	} cb_counter;

	///
	/// @brief 将计数器的值增加指定的值。
	///
	/// @note 溢出会发生环绕。
	///
	/// @param self
	/// @param value
	///
	__cb_force_inline void cb_counter_add(cb_counter *self, __template_cb_counter_type value)
	{
		if (self->_max_value == UINT32_MAX)
		{
			self->_count += value;
			return;
		}

		// 将要加的值约束在一个最小正周期内。
		value %= self->_max_value + 1;

		// 剩余多少达到最大值
		__template_cb_counter_type remain = self->_max_value - self->_count;
		if (value > remain)
		{
			// _count + value 会发生溢出

			// value 减去 remain, 然后假设 _count 已经加到最大值了。
			value -= remain;
			// _count = _max_value;

			// value 减去 1, 假设 _count 进一步加 1, 发生环绕，_count 变成 0.
			value -= 1;
			// _count = 0;

			// value 还剩下一点点，让为 0 的 _count 加上 value,
			// 相当于直接赋值。
			self->_count = value;
		}
		else
		{
			self->_count += value;
		}
	}

	///
	/// @brief 初始化计数器。
	///
	/// @param self
	/// @param current_value 计数器当前值。
	/// @param max_value 计数器允许的最大值。
	/// @return
	///
	__cb_force_inline void cb_counter_initialize(cb_counter *self,
												 __template_cb_counter_type current_value,
												 __template_cb_counter_type max_value)
	{
		self->_max_value = max_value;
		self->_count = 0;
		cb_counter_add(self, current_value);
	}

	///
	/// @brief 将计数器的值减少指定的值。
	///
	/// @note 溢出会发生环绕。
	///
	/// @param self
	/// @param value
	///
	__cb_force_inline void cb_counter_subtract(cb_counter *self, __template_cb_counter_type value)
	{
		if (self->_max_value == UINT32_MAX)
		{
			self->_count -= value;
			return;
		}

		// 将要减的值约束在一个最小正周期内。
		value %= self->_max_value + 1;
		if (value > self->_count)
		{
			// 假设将 _count 减到 0 后还剩下多少没减
			__template_cb_counter_type remain = value - self->_count;

			// 前面已经假设 _count 减到 0 了，接着假设 _count 继续减 1,
			// 环绕到最大值了，此时还剩下多少没减
			remain -= 1;

			// 最大值减去剩余的没减的值
			self->_count = self->_max_value - remain;
		}
		else
		{
			self->_count -= value;
		}
	}

	///
	/// @brief 将计数器的值递增 1.
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_increment(cb_counter *self)
	{
		cb_counter_add(self, 1);
	}

	///
	/// @brief 将计数器的值递减 1.
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_decrement(cb_counter *self)
	{
		cb_counter_subtract(self, 1);
	}

	///
	/// @brief 重置计数器。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_counter_reset(cb_counter *self)
	{
		self->_count = 0;
	}

	///
	/// @brief 获取计数器的当前值。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline __template_cb_counter_type cb_counter_current_value(cb_counter const *self)
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
	__cb_force_inline void cb_counter_set_current_value(cb_counter *self, __template_cb_counter_type value)
	{
		self->_count = 0;
		cb_counter_add(self, value);
	}

	/* #region 比较大小 */

	///
	/// @brief self 是否等于 other.
	///
	/// @param self
	/// @param other
	/// @return
	///
	__cb_force_inline bool cb_counter_equal(cb_counter const *self, cb_counter const *other)
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
	__cb_force_inline bool cb_counter_greater_than(cb_counter const *self, cb_counter const *other)
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
	__cb_force_inline bool cb_counter_less_than(cb_counter const *self, cb_counter const *other)
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
	__cb_force_inline bool cb_counter_greater_than_or_equal(cb_counter const *self, cb_counter const *other)
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
	__cb_force_inline bool cb_counter_less_than_or_equal(cb_counter const *self,
														 cb_counter const *other)
	{
		return self->_count <= other->_count;
	}

	/* #endregion */

#ifdef __cplusplus
}
#endif
