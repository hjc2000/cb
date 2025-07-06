#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct cb_int_circle_queue
{
	size_t _max_count;
	size_t _start;
	size_t _end;
	bool _is_full;

	int _array[];

} cb_int_circle_queue;

///
/// @brief 想要存放 N 个元素，需要准备多少个字节的内存块。
///
///
#define __cb_int_circle_queue_required_memory_block_size(N) (sizeof(cb_int_circle_queue) + N * sizeof(int))

///
/// @brief 想要存放 N 个元素，需要准备具有多少个元素的 uint64_t 数组。
///
///
#define __cb_int_circle_queue_required_uint64_array_count(N) (__cb_int_circle_queue_required_memory_block_size(N) / 8 + 1)

///
/// @brief 在 memory_block 上构造 cb_int_circle_queue.
///
/// @param memory_block uint64_t 的数组。
/// 	@note 使用 uint64_t 数组是为了保证内存对齐。
///
/// 	@note 使用 cb_int_circle_queue_required_uint64_array_count 来计算需要一个具有
/// 	多少个元素的 uint64_t 数组。
///
/// @param max_count 最大可以存放的元素个数。
///
/// @return
///
cb_int_circle_queue *cb_int_circle_queue_placement_new(uint64_t *memory_block, size_t max_count);

int *cb_int_circle_queue_get(cb_int_circle_queue *self, size_t index);

bool cb_int_circle_queue_is_empty(cb_int_circle_queue *self);

size_t cb_int_circle_queue_count(cb_int_circle_queue *self);

bool cb_int_circle_queue_enqueue(cb_int_circle_queue *self, int const *element);

bool cb_int_circle_queue_dequeue(cb_int_circle_queue *self, int *out);
