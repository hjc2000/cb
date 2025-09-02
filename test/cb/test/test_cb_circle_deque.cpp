#include "test_cb_circle_deque.h" // IWYU pragma: keep
#include "base/string/define.h"
#include <iostream>
#include <stdexcept>

#define __template_cb_circle_deque_element_type int
#define __template_cb_circle_deque_size ((int32_t)(100))
#include "cb/container/cb_circle_deque.h"

void cb::test::test_cb_circle_deque()
{
	std::cout << CODE_POS_STR;

	cb_circle_deque deque;
	cb_circle_deque_initialize(&deque);

	// 测试 1: 初始状态应为空
	if (cb_circle_deque_is_empty(&deque) == false)
	{
		throw std::runtime_error{CODE_POS_STR + "队列初始状态应为空。"};
	}

	if (cb_circle_deque_count(&deque) != 0)
	{
		throw std::runtime_error{CODE_POS_STR + "初始元素个数应为 0。"};
	}

	// 测试 2: 从尾部插入元素 10
	int data1 = 10;

	bool result = cb_circle_deque_push_back(&deque, &data1);
	if (result == false)
	{
		throw std::runtime_error{CODE_POS_STR + "无法将 10 插入到队尾。"};
	}

	if (cb_circle_deque_count(&deque) != 1)
	{
		throw std::runtime_error{CODE_POS_STR + "插入一个元素后，元素个数应为 1。"};
	}

	// 测试 3: 从尾部插入元素 20
	int data2 = 20;
	result = cb_circle_deque_push_back(&deque, &data2);
	if (result == false)
	{
		throw std::runtime_error{CODE_POS_STR + "无法将 20 插入到队尾。"};
	}

	if (cb_circle_deque_count(&deque) != 2)
	{
		throw std::runtime_error{CODE_POS_STR + "插入两个元素后，元素个数应为 2。"};
	}

	// 测试 4: 从头部插入元素 30
	int data3 = 30;
	result = cb_circle_deque_push_front(&deque, &data3);
	if (result == false)
	{
		throw std::runtime_error{CODE_POS_STR + "无法将 30 插入到队头。"};
	}

	if (cb_circle_deque_count(&deque) != 3)
	{
		throw std::runtime_error{CODE_POS_STR + "插入三个元素后，元素个数应为 3."};
	}

	int *get_result = cb_circle_deque_get(&deque, 0);
	if (get_result == nullptr)
	{
		throw std::runtime_error{CODE_POS_STR + "无法获取 0 索引位置的元素。"};
	}

	int value = *get_result;

	if (value != 30)
	{
		throw std::runtime_error{CODE_POS_STR + "0 索引位置的元素的值应该是 30."};
	}

	// 测试 5: 弹出队头，应为 30
	result = cb_circle_deque_pop_front(&deque, &value);
	if (result == false || value != 30)
	{
		throw std::runtime_error{CODE_POS_STR + "应从队头弹出 30，但结果不正确。"};
	}

	// 测试 6: 弹出队尾，应为 20
	result = cb_circle_deque_pop_back(&deque, &value);
	if (result == false || value != 20)
	{
		throw std::runtime_error{CODE_POS_STR + "应从队尾弹出 20，但结果不正确。"};
	}

	// 测试 7: 弹出队尾，应为 10（最后剩余元素）
	result = cb_circle_deque_pop_back(&deque, &value);
	if (result == false || value != 10)
	{
		throw std::runtime_error{CODE_POS_STR + "应从队尾弹出 10，但结果不正确。"};
	}

	// 测试 8: 验证队列为空
	if (!cb_circle_deque_is_empty(&deque))
	{
		throw std::runtime_error{CODE_POS_STR + "所有元素已弹出，队列应为空。"};
	}

	if (cb_circle_deque_count(&deque) != 0)
	{
		throw std::runtime_error{CODE_POS_STR + "队列为空时，元素个数应为 0。"};
	}

	// 测试 9: 空队列弹出应失败
	result = cb_circle_deque_pop_front(&deque, &value);
	if (result == true)
	{
		throw std::runtime_error{CODE_POS_STR + "空队列从队头弹出不应成功。"};
	}

	result = cb_circle_deque_pop_back(&deque, &value);
	if (result == true)
	{
		throw std::runtime_error{CODE_POS_STR + "空队列从队尾弹出不应成功。"};
	}

	// 测试 10: 填满队列
	for (int i = 0; i < __template_cb_circle_deque_size; ++i)
	{
		result = cb_circle_deque_push_back(&deque, &i);
		if (result == false)
		{
			throw std::runtime_error{"测试 10 失败：队列未满时插入失败。"};
		}
	}

	if (cb_circle_deque_count(&deque) != __template_cb_circle_deque_size)
	{
		throw std::runtime_error{"队列未达到满容量。"};
	}

	// 测试 11: 满队列插入应失败
	int dummy = 999;
	result = cb_circle_deque_push_back(&deque, &dummy);
	if (result == true)
	{
		throw std::runtime_error{"满队列从队尾插入不应成功。"};
	}

	result = cb_circle_deque_push_front(&deque, &dummy);
	if (result == true)
	{
		throw std::runtime_error{"测试 11 失败：满队列从队头插入不应成功。"};
	}

	// 测试 12: 弹出所有元素并验证顺序
	for (int i = 0; i < __template_cb_circle_deque_size; ++i)
	{
		result = cb_circle_deque_pop_front(&deque, &value);
		if (result == false || value != i)
		{
			throw std::runtime_error{"测试 12 失败：弹出顺序错误，期望值与实际值不符。"};
		}
	}

	if (!cb_circle_deque_is_empty(&deque))
	{
		throw std::runtime_error{"测试 12 失败：所有元素弹出后，队列应为空。"};
	}

	std::cout << "=== 所有测试通过！===" << std::endl;
}
