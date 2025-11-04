#pragma once

namespace cb
{
	///
	/// @brief 数码管显示的符号。
	///
	enum class LedSegmentSymbol
	{
		Number_0,
		Number_1,
		Number_2,
		Number_3,
		Number_4,
		Number_5,
		Number_6,
		Number_7,
		Number_8,
		Number_9,
		DigitalDot,
		A,
		B,
		C,
		c,
		d,
		E,
		F,
		G,
		H,
		i,
		J,
		L,
		n,
		o,
		P,
		q,
		r,
		S,
		t,
		U,
		u,
		V,
		v,
		y,

		///
		/// @brief 空。每一段 LED 灯都熄灭。
		///
		Space,

		///
		/// @brief 位于上方的横杠。
		///
		UpperDash,

		///
		/// @brief 位于中间的横杠。
		///
		MiddleDash,

		///
		/// @brief 位于下方的横杠。
		///
		LowerDash,
	};

} // namespace cb
