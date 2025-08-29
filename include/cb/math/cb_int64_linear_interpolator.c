#include "cb_int64_linear_interpolator.h" // IWYU pragma: keep

void cb_int64_linear_interpolator_initialize(cb_int64_linear_interpolator *self,
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

int64_t cb_int64_linear_interpolator_step(cb_int64_linear_interpolator *self)
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
