#include "test_counter.h" // IWYU pragma: keep
#include "cb/math/cb_counter.h"
#include <iostream>

void cb::test::test_counter()
{
	{
		std::cout << std::endl
				  << "测试递增: " << std::endl;

		cb_counter counter;
		cb_counter_initialize(&counter, 0, 9);
		for (int i = 0; i < 20; i++)
		{
			std::cout << cb_counter_current_value(&counter) << ", ";
			if ((i + 1) % 10 == 0)
			{
				std::cout << std::endl;
			}

			cb_counter_increment(&counter);
		}

		std::cout << std::endl;
	}

	{
		std::cout << std::endl
				  << "测试递减: " << std::endl;

		cb_counter counter;
		cb_counter_initialize(&counter, 0, 9);
		for (int i = 0; i < 20; i++)
		{
			std::cout << cb_counter_current_value(&counter) << ", ";
			if ((i + 1) % 10 == 0)
			{
				std::cout << std::endl;
			}

			cb_counter_decrement(&counter);
		}

		std::cout << std::endl;
	}

	{
		std::cout << std::endl
				  << "测试随机加减: " << std::endl;

		cb_counter counter;
		cb_counter_initialize(&counter, 0, 9);

		cb_counter_add(&counter, 107);
		std::cout << cb_counter_current_value(&counter) << std::endl;

		cb_counter_subtract(&counter, 106);
		std::cout << cb_counter_current_value(&counter) << std::endl;

		std::cout << std::endl;
	}
}
