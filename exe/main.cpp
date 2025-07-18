#include "base/string/define.h"
#include "base/string/ToHexString.h"
#include "cb/bit/big_endian_remote_bit_converter.h"
#include "cb/bit/little_endian_remote_bit_converter.h"
#include <cstdint>
#include <iostream>

int main()
{
	{
		std::cout << CODE_POS_STR;
		uint64_t num = 0x0123456789ABCDEF;
		uint8_t arr[sizeof(num)]{};
		cb_big_endian_remote_bit_converter_get_bytes_from_uint64(num, arr);
		base::ToHexStringOption option{};
		option.width = 2;
		for (uint8_t num : arr)
		{
			std::cout << base::ToHexString(num, option) << std::endl;
		}
	}

	{
		std::cout << CODE_POS_STR;
		uint64_t num = 0x0123456789ABCDEF;
		uint8_t arr[sizeof(num)]{};
		cb_little_endian_remote_bit_converter_get_bytes_from_uint64(num, arr);
		base::ToHexStringOption option{};
		option.width = 2;
		for (uint8_t num : arr)
		{
			std::cout << base::ToHexString(num, option) << std::endl;
		}
	}
}
