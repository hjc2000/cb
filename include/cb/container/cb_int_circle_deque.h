#pragma once
#include "cb/cb_define.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define __template_cb_int_circle_deque_element_type int
#define __template_cb_int_circle_deque_size 100

	typedef struct cb_int_circle_deque
	{
		__template_cb_int_circle_deque_element_type _buffer[__template_cb_int_circle_deque_size];
		uint32_t _begin;
		uint32_t _end;
		bool _is_full;

	} cb_int_circle_deque;

	__cb_force_inline void cb_int_circle_deque_initialize(cb_int_circle_deque *self)
	{
		self->_begin = 0;
		self->_end = 0;
		self->_is_full = false;
	}

	__cb_force_inline int cb_int_circle_deque_count(cb_int_circle_deque *self)
	{
		if (self->_is_full)
		{
			return __template_cb_int_circle_deque_size;
		}

		return self->_end - self->_begin;
	}

	__cb_force_inline bool cb_int_circle_deque_is_empty(cb_int_circle_deque *self)
	{
		return self->_begin == self->_end && !self->_is_full;
	}

	__cb_force_inline bool cb_int_circle_deque_push_back(cb_int_circle_deque *self,
														 __template_cb_int_circle_deque_element_type value)
	{
		if (self->_is_full)
		{
			return false;
		}

		self->_buffer[self->_end] = value;
		self->_end = (self->_end + 1) % __template_cb_int_circle_deque_size;
		if (self->_end == self->_begin)
		{
			self->_is_full = true;
		}

		return true;
	}

	__cb_force_inline bool cb_int_circle_deque_push_front(cb_int_circle_deque *self,
														  __template_cb_int_circle_deque_element_type value)
	{
		if (self->_is_full)
		{
			return false;
		}

		self->_begin = (self->_begin + __template_cb_int_circle_deque_size - 1) % __template_cb_int_circle_deque_size;
		return true;
	}

	__cb_force_inline bool cb_int_circle_deque_pop_back(cb_int_circle_deque *self,
														__template_cb_int_circle_deque_element_type *value)
	{
		if (cb_int_circle_deque_is_empty(self))
		{
			return false;
		}

		*value = self->_buffer[self->_end - 1];
		self->_end = (self->_end + __template_cb_int_circle_deque_size - 1) % __template_cb_int_circle_deque_size;
		self->_is_full = false;
		return true;
	}

	__cb_force_inline bool cb_int_circle_deque_pop_front(cb_int_circle_deque *self,
														 __template_cb_int_circle_deque_element_type *value)
	{
		if (cb_int_circle_deque_is_empty(self))
		{
			return false;
		}

		*value = self->_buffer[self->_begin];
		self->_begin = (self->_begin + 1) % __template_cb_int_circle_deque_size;
		self->_is_full = false;
		return false;
	}

#ifdef __cplusplus
}
#endif
