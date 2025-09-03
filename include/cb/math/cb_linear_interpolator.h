#pragma once
#include "cb/cb_define.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief 模板参数。线性插值器的类型。
///
///
#ifndef __template_cb_linear_interpolator_type
	#define __template_cb_linear_interpolator_type int64_t
#endif

	typedef struct cb_linear_interpolator
	{
		__template_cb_linear_interpolator_type _current_value;
		__template_cb_linear_interpolator_type _end_value;
		__template_cb_linear_interpolator_type _step_length;
	} cb_linear_interpolator;

	__cb_force_inline void cb_linear_interpolator_initialize(cb_linear_interpolator *self,
															 __template_cb_linear_interpolator_type current_value,
															 __template_cb_linear_interpolator_type end_value,
															 __template_cb_linear_interpolator_type step_length)
	{
		self->_current_value = current_value;
		self->_end_value = end_value;

		if (step_length < 0)
		{
			step_length = -step_length;
		}

		self->_step_length = step_length;
	}

	__cb_force_inline __template_cb_linear_interpolator_type cb_linear_interpolator_current_value(cb_linear_interpolator const *self)
	{
		return self->_current_value;
	}

	__cb_force_inline void cb_linear_interpolator_set_current_value(cb_linear_interpolator *self, __template_cb_linear_interpolator_type value)
	{
		self->_current_value = value;
	}

	__cb_force_inline __template_cb_linear_interpolator_type cb_linear_interpolator_end_value(cb_linear_interpolator const *self)
	{
		return self->_end_value;
	}

	__cb_force_inline void cb_linear_interpolator_set_end_value(cb_linear_interpolator *self, __template_cb_linear_interpolator_type value)
	{
		self->_end_value = value;
	}

	__cb_force_inline __template_cb_linear_interpolator_type cb_linear_interpolator_step_length(cb_linear_interpolator const *self)
	{
		return self->_step_length;
	}

	__cb_force_inline void cb_linear_interpolator_set_step_length(cb_linear_interpolator *self, __template_cb_linear_interpolator_type value)
	{
		self->_step_length = value;
	}

	__cb_force_inline __template_cb_linear_interpolator_type cb_linear_interpolator_step(cb_linear_interpolator *self)
	{
		__template_cb_linear_interpolator_type error = self->_end_value - self->_current_value;
		if (error < 0)
		{
			error = -error;
		}

		if (error < self->_step_length)
		{
			// 差距小于 1 个步长，直接赋值为结束值。
			self->_current_value = self->_end_value;
			return self->_current_value;
		}

		// 差距大于 1 个步长。
		// 从正向和负向逼近结束值。
		if (self->_current_value < self->_end_value)
		{
			self->_current_value += self->_step_length;
		}
		else if (self->_current_value > self->_end_value)
		{
			self->_current_value -= self->_step_length;
		}

		return self->_current_value;
	}

#ifdef __cplusplus
}
#endif
