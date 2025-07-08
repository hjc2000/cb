#pragma once
#include "cb/define.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cb_int64_linear_interpolator
	{
		int64_t _current_value;
		int64_t _end_value;
		int64_t _step_length;
	} cb_int64_linear_interpolator;

	__cb_force_inline void cb_int64_linear_interpolator_initialize(cb_int64_linear_interpolator *self,
																   int64_t current_value,
																   int64_t end_value,
																   int64_t step_length)
	{
		self->_current_value = current_value;
		self->_end_value = end_value;

		if (step_length < 0)
		{
			step_length = -step_length;
		}

		self->_step_length = step_length;
	}

	__cb_force_inline int64_t cb_int64_linear_interpolator_current_value(cb_int64_linear_interpolator const *self)
	{
		return self->_current_value;
	}

	__cb_force_inline void cb_int64_linear_interpolator_set_current_value(cb_int64_linear_interpolator *self, int64_t value)
	{
		self->_current_value = value;
	}

	__cb_force_inline int64_t cb_int64_linear_interpolator_end_value(cb_int64_linear_interpolator const *self)
	{
		return self->_end_value;
	}

	__cb_force_inline void cb_int64_linear_interpolator_set_end_value(cb_int64_linear_interpolator *self, int64_t value)
	{
		self->_end_value = value;
	}

	__cb_force_inline int64_t cb_int64_linear_interpolator_step_length(cb_int64_linear_interpolator const *self)
	{
		return self->_step_length;
	}

	__cb_force_inline void cb_int64_linear_interpolator_set_step_length(cb_int64_linear_interpolator *self, int64_t value)
	{
		self->_step_length = value;
	}

	__cb_force_inline int64_t cb_int64_linear_interpolator_update(cb_int64_linear_interpolator *self)
	{
		int64_t error = self->_end_value - self->_current_value;
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
