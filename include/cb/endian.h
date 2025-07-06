#pragma once

///
/// @brief 字节序枚举。
///
///
typedef enum cb_endian_enum
{
	cb_endian_big_endian,
	cb_endian_little_endian,
} cb_endian_enum;

///
/// @brief 获取本机字节序
///
/// @return
///
cb_endian_enum cb_local_host_endian();
