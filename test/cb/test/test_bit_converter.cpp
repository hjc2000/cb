#include "test_bit_converter.h" // IWYU pragma: keep
#include "base/string/define.h"
#include "base/string/ToHexString.h"
#include "cb/bit/cb_big_endian_remote_bit_converter.h"
#include "cb/bit/cb_bit_converter.h"
#include "cb/bit/cb_little_endian_remote_bit_converter.h"
#include <cstdint>
#include <iostream>
#include <stdexcept>

void cb::test::test_bit_converter()
{
	uint8_t array[] = {0, 1, 2, 3, 4, 5, 6, 7};

	{
		uint16_t value = cb_bit_converter_byte_array_to_uint16(array);
		std::cout << value << std::endl;
		if (value != 256)
		{
			throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
		}
	}

	{
		uint32_t value = cb_bit_converter_byte_array_to_uint32(array);
		std::cout << value << std::endl;
		if (value != 50462976)
		{
			throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
		}
	}

	{
		uint64_t value = cb_bit_converter_byte_array_to_uint64(array);
		std::cout << value << std::endl;
		if (value != static_cast<uint64_t>(506097522914230528))
		{
			throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
		}
	}

	{
		float value = 1.0;
		uint8_t *array = reinterpret_cast<uint8_t *>(&value);
		value = cb_bit_converter_byte_array_to_float(array);
		std::cout << value << std::endl;
		if (value != static_cast<float>(1.0))
		{
			throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
		}
	}

	{
		double value = 1.0;
		uint8_t *array = reinterpret_cast<uint8_t *>(&value);
		value = cb_bit_converter_byte_array_to_double(array);
		std::cout << value << std::endl;
		if (value != 1.0)
		{
			throw std::runtime_error{CODE_POS_STR + "测试不通过。"};
		}
	}

	std::cout << "测试通过。" << std::endl;
}

void cb::test::test_little_endian_remote_bit_converter()
{
	std::cout << CODE_POS_STR;
	uint64_t num = 0x0123456789ABCDEF;
	uint8_t arr[sizeof(num)]{};
	cb_little_endian_remote_bit_converter_get_bytes_from_uint64(num, arr);
	base::ToHexStringOptions options{};
	options.width = 2;
	for (uint8_t num : arr)
	{
		std::cout << base::ToHexString(num, options) << std::endl;
	}

	std::cout << std::endl;
}

void cb::test::test_big_endian_remote_bit_converter()
{
	std::cout << CODE_POS_STR;
	uint64_t num = 0x0123456789ABCDEF;
	uint8_t arr[sizeof(num)]{};
	cb_big_endian_remote_bit_converter_get_bytes_from_uint64(num, arr);
	base::ToHexStringOptions options{};
	options.width = 2;
	for (uint8_t num : arr)
	{
		std::cout << base::ToHexString(num, options) << std::endl;
	}

	std::cout << std::endl;
}
