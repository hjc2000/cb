#pragma once
#include <stdbool.h>

#define __template_cb_circle_deque_element_type int
#define __template_cb_circle_deque_size ((int32_t)(100))
#include "cb/container/cb_circle_deque.h"

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cb_int_circle_deque
	{
		cb_circle_deque _deque;

	} cb_int_circle_deque;

	///
	/// @brief int 类型的循环队列。
	///
	///
	typedef struct cb_int_circle_deque cb_int_circle_deque;

	///
	/// @brief 初始化。
	///
	/// @param self
	/// @return
	///
	void cb_int_circle_deque_initialize(cb_int_circle_deque *self);

	///
	/// @brief 队列中的元素个数。
	///
	/// @param self
	/// @return
	///
	int cb_int_circle_deque_count(cb_int_circle_deque *self);

	///
	/// @brief 队列为空。
	///
	/// @param self
	/// @return
	///
	bool cb_int_circle_deque_is_empty(cb_int_circle_deque *self);

	///
	/// @brief 向队列末尾添加元素。
	///
	/// @param self
	/// @param value
	/// @return 添加成功返回 true, 添加失败返回 false.
	///
	bool cb_int_circle_deque_push_back(cb_int_circle_deque *self, int *value);

	///
	/// @brief 向队列头部添加元素。
	///
	/// @param self
	/// @param value
	/// @return 添加成功返回 true, 添加失败返回 false.
	///
	bool cb_int_circle_deque_push_front(cb_int_circle_deque *self, int *value);

	///
	/// @brief 弹出队列末尾元素。
	///
	/// @param self
	/// @param out
	/// @return
	///
	bool cb_int_circle_deque_pop_back(cb_int_circle_deque *self, int *out);

	///
	/// @brief 弹出队列头部元素。
	///
	/// @param self
	/// @param out
	/// @return
	///
	bool cb_int_circle_deque_pop_front(cb_int_circle_deque *self, int *out);

	///
	/// @brief 获取队列中指定索引的元素。
	///
	/// @param self
	/// @param index
	///
	/// @return 如果指定索引处有元素，则返回该元素的指针，否则返回空指针。
	///
	int *cb_int_circle_deque_get(cb_int_circle_deque *self, int index);

	///
	/// @brief 清空队列。
	///
	/// @param self
	/// @return
	///
	void cb_int_circle_deque_clear(cb_int_circle_deque *self);

#ifdef __cplusplus
}
#endif
