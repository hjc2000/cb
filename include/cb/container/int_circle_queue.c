#include "int_circle_queue.h"
#include <stdbool.h>
#include <stddef.h>

static void cb_int_circle_queue_add_start(cb_int_circle_queue *self)
{
	self->_start++;
	self->_start %= self->_max_count;
}

static void cb_int_circle_queue_add_end(cb_int_circle_queue *self)
{
	self->_end++;
	self->_end %= self->_max_count;
}

cb_int_circle_queue *cb_int_circle_queue_placement_new(uint64_t *memory_block,
													   size_t max_count)
{
	cb_int_circle_queue *ret = (cb_int_circle_queue *)(memory_block);
	ret->_max_count = max_count;
	ret->_start = 0;
	ret->_end = 0;
	ret->_is_full = false;
	return ret;
}

int *cb_int_circle_queue_get(cb_int_circle_queue *self, size_t index)
{
	if (cb_int_circle_queue_is_empty(self))
	{
		return NULL;
	}

	size_t pos = (self->_start + index) % self->_max_count;
	return &self->_array[pos];
}

bool cb_int_circle_queue_is_empty(cb_int_circle_queue *self)
{
	if (self->_start == self->_end && !self->_is_full)
	{
		return true;
	}

	return false;
}

size_t cb_int_circle_queue_count(cb_int_circle_queue *self)
{
	if (self->_is_full)
	{
		return self->_max_count;
	}

	if (self->_end < self->_start)
	{
		// 发生了环绕。
		return self->_max_count - (self->_start - self->_end);
	}

	return self->_end - self->_start;
}

bool cb_int_circle_queue_enqueue(cb_int_circle_queue *self,
								 int const *element)
{
	if (self->_is_full)
	{
		return false;
	}

	self->_array[self->_end] = *element;
	cb_int_circle_queue_add_end(self);
	if (self->_start == self->_end)
	{
		self->_is_full = true;
	}

	return true;
}

bool cb_int_circle_queue_dequeue(cb_int_circle_queue *self, int *out)
{
	if (cb_int_circle_queue_is_empty(self))
	{
		return false;
	}

	*out = self->_array[self->_start];
	cb_int_circle_queue_add_start(self);
	return true;
}
