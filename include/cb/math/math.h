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
		{
			// 最大公因数 gcd 可以乘上一个整数得到 a, 也可以乘上一个整数得到 b.
			//
			// 当 a, b 其中一个为 0, 另一个不为 0 时，gcd 为不为 0 的那个的绝对值。
			// 假设 a = 0, b != 0, 则此时 gcd = b, 满足
			// gcd * 0 = a
			// gcd * 1 = b
			// 所以 gcd 可以称得上是最大公因数。
			//
			// 当 a, b 都为 0 时，gcd = 0, 满足
			// gcd * 0 = a
			// gcd * 0 = b
			// 所以 gcd 可以称得上是最大公因数。

			if (a == 0)
			{
				return cb::abs(b);
			}

			if (b == 0)
			{
				return cb::abs(a);
			}

			// 没必要写出
			//
			// 	if (a == 0 && b == 0)
			// 	{
			// 		return 0;
			// 	}
			//
			// 因为前面的 2 个 if 已经能处理这种情况了。
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
		T mul = cb::abs(a * b);
		if (mul == 0)
		{
			// 最大公倍数 lcm 满足 a 乘上一个整数等于 lcm, b 乘上一个整数等于 lcm.
			//
			// 当 a, b 其中一个为 0, 时，想要让 a, b 乘上整数都能等于 lcm, 因为 0
			// 乘上什么都等于 0, 所以只能让 lcm 等于 0, 然后
			// a * 0 = lcm
			// b * 0 = lcm
			return 0;
		}

		T gcd = cb::gcd(a, b);

		// 如果最大公因数是其中的一个数，则另一个数一定是它们的最小公倍数。
		if (gcd == a)
		{
			return b;
		}

		if (gcd == b)
		{
			return a;
		}

		return mul / gcd;
	}

} // namespace cb
