#include "cb_counter_32.h" // IWYU pragma: keep

void cb_counter_32_initialize(cb_counter_32 *self,
							  uint32_t current_value,
							  uint32_t max_value)
{
	self->_max_value = max_value;
	cb_counter_32_add(self, current_value);
}

void cb_counter_32_add(cb_counter_32 *self, uint32_t value)
{
	// 将要加的值约束在一个最小正周期内。
	value %= self->_max_value + 1;

	// 剩余多少达到最大值
	uint32_t remain = self->_max_value - self->_count;
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

void cb_counter_32_subtract(cb_counter_32 *self, uint32_t value)
{
	// 将要减的值约束在一个最小正周期内。
	value %= self->_max_value + 1;
	if (value > self->_count)
	{
		// 假设将 _count 减到 0 后还剩下多少没减
		uint32_t remain = value - self->_count;

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
