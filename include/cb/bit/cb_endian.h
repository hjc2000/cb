#pragma once
#include "cb/cb_define.h"
#include <stdint.h>

#ifdef __cplusplus

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
		constexpr Endian NativeEndian()
		{
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
			return Endian::LittleEndian;
	#else
			return Endian::BigEndian;
	#endif
		}

	} // namespace endian
} // namespace cb

#endif

#ifdef __cplusplus
extern "C"
{
#endif

	///
	/// @brief 字节序枚举。
	///
	///
	typedef enum cb_endian_enum
	{
		cb_endian_little_endian,
		cb_endian_big_endian,
	} cb_endian_enum;

	///
	/// @brief 获取本机字节序。
	///
	/// @return
	///
	__cb_force_inline cb_endian_enum cb_endian_native_endian()
	{
		uint16_t number = 1;
		uint8_t *p = (uint8_t *)&number;
		if (p[0])
		{
			return cb_endian_little_endian;
		}

		return cb_endian_big_endian;
	}

#ifdef __cplusplus
}
#endif
