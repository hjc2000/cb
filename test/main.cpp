// IWYU pragma: begin_keep

#include "base/string/define.h"
#include "base/string/ToHexString.h"
#include "cb/bit/cb_big_endian_remote_bit_converter.h"
#include "cb/bit/cb_little_endian_remote_bit_converter.h"
#include "cb/test/test_bit_converter.h"
#include "cb/test/test_counter_32.h"
#include <cstdint>
#include <iostream>

// IWYU pragma: end_keep

int main()
{
	// cb::test::test_big_endian_remote_bit_converter();
	// cb::test::test_little_endian_remote_bit_converter();
	cb::test::test_counter_32();
}
