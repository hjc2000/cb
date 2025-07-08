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

	void cb_int64_linear_interpolator_initialize(cb_int64_linear_interpolator *self,
												 int64_t current_value,
												 int64_t end_value,
												 int64_t step_length);

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

	int64_t cb_int64_linear_interpolator_update(cb_int64_linear_interpolator *self);

#ifdef __cplusplus
}
#endif
