// IWYU pragma: begin_keep

#include "base/string/define.h"
#include "base/string/ToHexString.h"
#include "cb/math/cb_int64_fraction.h"
#include <cstdint>
#include <iostream>

// IWYU pragma: end_keep

int main()
{
	constexpr uint64_t factor = static_cast<uint64_t>(1) << 30;
	cb::Int64Fraction f1 = static_cast<int64_t>(cb::Int64Fraction{100, 3000} * factor);
	std::cout << "f1 = " << f1.ToString() << std::endl;

	f1 *= 3000;
	f1 *= 10;
	f1 /= factor;
	std::cout << "f1 = " << f1.ToString() << std::endl;
	std::cout << "static_cast<int64_t>(f1) = " << static_cast<int64_t>(f1) << std::endl;
	return 0;
}
