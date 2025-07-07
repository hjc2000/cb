#include "cb/math/counter.h"
#include <iostream>

int main()
{
	cb_counter_32 counter{};
	cb_counter_32_initialize(&counter, 0, 9);

	for (int i = 0; i < 30; i++)
	{
		std::cout << cb_counter_32_current_value(&counter) << std::endl;
		cb_counter_32_add(&counter, 1);
	}
}
