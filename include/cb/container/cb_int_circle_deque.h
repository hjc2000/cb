#pragma once
#include "cb/cb_define.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define __template_cb_int_circle_deque_element_type int
#define __template_cb_int_circle_deque_size 100

	///
	/// @brief int 类型的循环队列。
	///
	///
	typedef struct cb_int_circle_deque
	{
		__template_cb_int_circle_deque_element_type _buffer[__template_cb_int_circle_deque_size];
		uint32_t _begin;
		uint32_t _end;
		bool _is_full;

	} cb_int_circle_deque;

	///
	/// @brief 初始化。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_int_circle_deque_initialize(cb_int_circle_deque *self)
	{
		self->_begin = 0;
		self->_end = 0;
		self->_is_full = false;
	}

	///
	/// @brief 队列中的元素个数。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline int cb_int_circle_deque_count(cb_int_circle_deque *self)
	{
		if (self->_is_full)
		{
			return __template_cb_int_circle_deque_size;
		}

		if (self->_end >= self->_begin)
		{
			return self->_end - self->_begin;
		}

		return __template_cb_int_circle_deque_size - (self->_begin - self->_end);
	}

	///
	/// @brief 队列为空。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline bool cb_int_circle_deque_is_empty(cb_int_circle_deque *self)
	{
		return self->_begin == self->_end && !self->_is_full;
	}

	///
	/// @brief 向队列末尾添加元素。
	///
	/// @param self
	/// @param value
	/// @return 添加成功返回 true, 添加失败返回 false.
	///
	__cb_force_inline bool cb_int_circle_deque_push_back(cb_int_circle_deque *self,
														 __template_cb_int_circle_deque_element_type *value)
	{
		if (value == NULL)
		{
			return false;
		}

		if (self->_is_full)
		{
			return false;
		}

		self->_buffer[self->_end] = *value;
		self->_end = (self->_end + 1) % __template_cb_int_circle_deque_size;
		if (self->_end == self->_begin)
		{
			self->_is_full = true;
		}

		return true;
	}

	///
	/// @brief 向队列头部添加元素。
	///
	/// @param self
	/// @param value
	/// @return 添加成功返回 true, 添加失败返回 false.
	///
	__cb_force_inline bool cb_int_circle_deque_push_front(cb_int_circle_deque *self,
														  __template_cb_int_circle_deque_element_type *value)
	{
		if (value == NULL)
		{
			return false;
		}

		if (self->_is_full)
		{
			return false;
		}

		self->_begin = (self->_begin + __template_cb_int_circle_deque_size - 1) % __template_cb_int_circle_deque_size;
		self->_buffer[self->_begin] = *value;
		return true;
	}

	///
	/// @brief 弹出队列末尾元素。
	///
	/// @param self
	/// @param out
	/// @return
	///
	__cb_force_inline bool cb_int_circle_deque_pop_back(cb_int_circle_deque *self,
														__template_cb_int_circle_deque_element_type *out)
	{
		if (cb_int_circle_deque_is_empty(self))
		{
			return false;
		}

		if (out != NULL)
		{
			*out = self->_buffer[self->_end - 1];
		}

		self->_end = (self->_end + __template_cb_int_circle_deque_size - 1) % __template_cb_int_circle_deque_size;
		self->_is_full = false;
		return true;
	}

	///
	/// @brief 弹出队列头部元素。
	///
	/// @param self
	/// @param out
	/// @return
	///
	__cb_force_inline bool cb_int_circle_deque_pop_front(cb_int_circle_deque *self,
														 __template_cb_int_circle_deque_element_type *out)
	{
		if (cb_int_circle_deque_is_empty(self))
		{
			return false;
		}

		if (out != NULL)
		{
			*out = self->_buffer[self->_begin];
		}

		self->_begin = (self->_begin + 1) % __template_cb_int_circle_deque_size;
		self->_is_full = false;
		return true;
	}

	///
	/// @brief 获取队列中指定索引的元素。
	///
	/// @param self
	/// @param index
	///
	/// @return 如果指定索引处有元素，则返回该元素的指针，否则返回空指针。
	///
	__cb_force_inline __template_cb_int_circle_deque_element_type *cb_int_circle_deque_get(cb_int_circle_deque *self,
																						   int index)
	{
		if (index < 0 || index >= cb_int_circle_deque_count(self))
		{
			return NULL;
		}

		uint32_t pos = (self->_begin + index) % __template_cb_int_circle_deque_size;
		return &self->_buffer[pos];
	}

	///
	/// @brief 清空队列。
	///
	/// @param self
	/// @return
	///
	__cb_force_inline void cb_int_circle_deque_clear(cb_int_circle_deque *self)
	{
		self->_begin = 0;
		self->_end = 0;
		self->_is_full = false;
	}

#ifdef __cplusplus
}
#endif
