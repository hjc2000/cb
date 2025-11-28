#pragma once
#include "cb/math/abs.h"

namespace cb
{
	template <typename T>
	constexpr T gcd(T a, T b)
	{
		if (a == 0)
		{
			return cb::abs(b);
		}

		if (b == 0)
		{
			return cb::abs(a);
		}

		a = cb::abs(a);
		b = cb::abs(b);

		while (true)
		{
			T mod = a % b;
			if (mod == 0)
			{
				return b;
			}

			a = b;
			b = mod;
		}
	}

} // namespace cb
