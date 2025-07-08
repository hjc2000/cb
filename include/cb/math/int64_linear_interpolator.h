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

#ifdef __cplusplus
}
#endif
