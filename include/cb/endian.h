#pragma once

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
	/// @brief 本机字节序。
	///
	///
	extern cb_endian_enum const cb_native_endian;

#ifdef __cplusplus
}
#endif
