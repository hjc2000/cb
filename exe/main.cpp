#include "cb/reverse.h"
#include <iostream>
#include <stdint.h>
#include <string>

int main()
{
	uint8_t arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	cb_reverse_byte_array_per_element(arr, 4, 2);
	for (uint8_t num : arr)
	{
		std::cout << std::to_string(num) << std::endl;
	}
}
