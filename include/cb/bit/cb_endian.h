#pragma once

namespace cb
{
	namespace endian
	{
		enum class Endian
		{
			LittleEndian,
			BigEndian,
		};

		///
		/// @brief 获取本机字节序。
		///
		/// @return
		///
		constexpr cb::endian::Endian NativeEndian()
		{
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
			return Endian::LittleEndian;
#else
			return Endian::BigEndian;
#endif
		}

	} // namespace endian
} // namespace cb
