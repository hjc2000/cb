#include "test_reverse.h" // IWYU pragma: keep
#include "base/stream/ReadOnlySpan.h"
#include "base/string/ToHexString.h"
#include "cb/bit/reverse.h"
#include <iostream>
#include <stdint.h>

void cb::test::test_reverse()
{
	{
		uint8_t array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		cb_reverse_byte_array(array, sizeof(array));

		base::ReadOnlySpan span{array, sizeof(array)};
		base::ToHexStringOptions options;
		options.width = 2;
		std::cout << base::ToHexString(span, options) << std::endl;
	}

	{
		uint8_t array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		cb_reverse_byte_array_per_element(array, sizeof(array) / 2, 2);

		base::ReadOnlySpan span{array, sizeof(array)};
		base::ToHexStringOptions options;
		options.width = 2;
		std::cout << base::ToHexString(span, options) << std::endl;
	}
}
