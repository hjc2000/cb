#pragma once

namespace cb
{
	///
	/// @brief 求绝对值。
	///
	/// @param value
	/// @return
	///
	template <typename T>
	constexpr T abs(T const &value)
	{
		if (value < T{})
		{
			return -value;
		}

		return value;
	}

	///
	/// @brief 求最大公约数。
	///
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

	///
	/// @brief 求最小公倍数。
	///
	template <typename T>
	constexpr T lcm(T a, T b)
	{
		return cb::abs(a * b) / cb::gcd(a, b);
	}

} // namespace cb
