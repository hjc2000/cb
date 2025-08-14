#include "test_endian.h" // IWYU pragma: keep
#include "cb/bit/endian.h"
#include <iostream>

void cb::test::test_endian()
{
	cb_endian_enum endian = cb_endian_native_endian();

	if (endian == cb_endian_enum::cb_endian_little_endian)
	{
		std::cout << "小端序" << std::endl;
	}
	else
	{
		std::cout << "大端序" << std::endl;
	}
}
