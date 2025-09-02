#include "cb_int_circle_deque.h" // IWYU pragma: keep

#define __template_cb_circle_deque_element_type int
#define __template_cb_circle_deque_size ((int32_t)(100))
#include "cb/container/cb_circle_deque.h"

typedef struct cb_int_circle_deque
{
	cb_circle_deque _deque;

} cb_int_circle_deque;

void cb_int_circle_deque_initialize(cb_int_circle_deque *self)
{
	cb_circle_deque_initialize(&self->_deque);
}

int cb_int_circle_deque_count(cb_int_circle_deque *self)
{
	return cb_circle_deque_count(&self->_deque);
}

bool cb_int_circle_deque_is_empty(cb_int_circle_deque *self)
{
	return cb_circle_deque_is_empty(&self->_deque);
}

bool cb_int_circle_deque_push_back(cb_int_circle_deque *self, int *value)
{
	return cb_circle_deque_push_back(&self->_deque, value);
}

bool cb_int_circle_deque_push_front(cb_int_circle_deque *self, int *value)
{
	return cb_circle_deque_push_front(&self->_deque, value);
}

bool cb_int_circle_deque_pop_back(cb_int_circle_deque *self, int *out)
{
	return cb_circle_deque_pop_back(&self->_deque, out);
}

bool cb_int_circle_deque_pop_front(cb_int_circle_deque *self,
								   int *out)
{
	return cb_circle_deque_pop_front(&self->_deque, out);
}

int *cb_int_circle_deque_get(cb_int_circle_deque *self,
							 int index)
{
	return cb_circle_deque_get(&self->_deque, index);
}

void cb_int_circle_deque_clear(cb_int_circle_deque *self)
{
	cb_circle_deque_clear(&self->_deque);
}
