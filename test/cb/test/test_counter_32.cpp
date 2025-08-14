#include "test_counter_32.h" // IWYU pragma: keep
#include "cb/math/cb_counter_32.h"
#include <cstdint>
#include <iostream>

void cb::test::test_counter_32()
{
	{
		std::cout << std::endl
				  << "测试递增: " << std::endl;

		cb_counter_32 counter;
		cb_counter_32_initialize(&counter, 0, 9);
		for (int i = 0; i < 20; i++)
		{
			uint32_t value = cb_counter_32_current_value(&counter);
			std::cout << value << ", ";
			if ((i + 1) % 10 == 0)
			{
				std::cout << std::endl;
			}

			cb_counter_32_increment(&counter);
		}

		std::cout << std::endl;
	}

	{
		std::cout << std::endl
				  << "测试递减: " << std::endl;

		cb_counter_32 counter;
		cb_counter_32_initialize(&counter, 0, 9);
		for (int i = 0; i < 20; i++)
		{
			uint32_t value = cb_counter_32_current_value(&counter);
			std::cout << value << ", ";
			if ((i + 1) % 10 == 0)
			{
				std::cout << std::endl;
			}

			cb_counter_32_decrement(&counter);
		}

		std::cout << std::endl;
	}
}
