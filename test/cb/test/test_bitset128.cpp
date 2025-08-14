#include "test_bitset128.h" // IWYU pragma: keep
#include "base/stream/ReadOnlySpan.h"
#include "base/string/define.h"
#include "base/string/ToHexString.h"
#include "cb/bit/bitset128.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

void cb::test::test_bitset128()
{
	cb_bitset128 bitset;
	cb_bitset128_initialize(&bitset);
	cb_bitset128_write_bit(&bitset, 8 * 12, true);
	bool value = cb_bitset128_read_bit(&bitset, 8 * 12);
	if (!value)
	{
		throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
	}

	for (size_t i = 0; i < sizeof(bitset._array); i++)
	{
		cb_bitset128_write_bit(&bitset, 8 * i, true);
		cb_bitset128_write_bit(&bitset, 8 * i + 2, true);
	}

	base::ReadOnlySpan span{bitset._array, sizeof(bitset._array)};
	base::ToHexStringOptions options{};
	options.width = 2;
	std::cout << base::ToHexString(span, options) << std::endl;
}
