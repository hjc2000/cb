#pragma once
#include "cb/endian.h"
#include <stdbool.h>
#include <stdint.h>

///
/// @brief 自适应比特转换器。
///
///
typedef struct cb_auto_bit_converter
{
	///
	/// @brief 是否应该翻转字节数组。
	///
	/// @note 本机字节序和远程字节序不同时就需要翻转字节数组。
	///
	///
	bool _should_reverse;

} cb_auto_bit_converter;

void cb_auto_bit_converter_initialize(cb_auto_bit_converter *self, cb_endian_enum remote_endian);

/* #region 转数字 */

uint16_t cb_auto_bit_converter_to_uint16(cb_auto_bit_converter *self,
										 uint8_t const *buffer,
										 int32_t offset);

int16_t cb_auto_bit_converter_to_int16(cb_auto_bit_converter *self,
									   uint8_t const *buffer,
									   int32_t offset);

uint32_t cb_auto_bit_converter_to_uint32(cb_auto_bit_converter *self,
										 uint8_t const *buffer,
										 int32_t offset);

int32_t cb_auto_bit_converter_to_int32(cb_auto_bit_converter *self,
									   uint8_t const *buffer,
									   int32_t offset);

uint64_t cb_auto_bit_converter_to_uint64(cb_auto_bit_converter *self,
										 uint8_t const *buffer,
										 int32_t offset);

int64_t cb_auto_bit_converter_to_int64(cb_auto_bit_converter *self,
									   uint8_t const *buffer,
									   int32_t offset);

float cb_auto_bit_converter_to_float(cb_auto_bit_converter *self,
									 uint8_t const *buffer,
									 int32_t offset);

double cb_auto_bit_converter_to_double(cb_auto_bit_converter *self,
									   uint8_t const *buffer,
									   int32_t offset);

/* #endregion */

/* #region 转字节数组 */

void cb_auto_bit_converter_get_bytes_from_uint16(cb_auto_bit_converter *self,
												 uint16_t value,
												 uint8_t *out_buffer,
												 int32_t offset);

void cb_auto_bit_converter_get_bytes_from_int16(cb_auto_bit_converter *self,
												int16_t value,
												uint8_t *out_buffer,
												int32_t offset);

void cb_auto_bit_converter_get_bytes_from_uint32(cb_auto_bit_converter *self,
												 uint32_t value,
												 uint8_t *out_buffer,
												 int32_t offset);

void cb_auto_bit_converter_get_bytes_from_int32(cb_auto_bit_converter *self,
												int32_t value,
												uint8_t *out_buffer,
												int32_t offset);

void cb_auto_bit_converter_get_bytes_from_uint64(cb_auto_bit_converter *self,
												 uint64_t value,
												 uint8_t *out_buffer,
												 int32_t offset);

void cb_auto_bit_converter_get_bytes_from_int64(cb_auto_bit_converter *self,
												int64_t value,
												uint8_t *out_buffer,
												int32_t offset);

void cb_auto_bit_converter_get_bytes_from_float(cb_auto_bit_converter *self,
												float value,
												uint8_t *out_buffer,
												int32_t offset);

void cb_auto_bit_converter_get_bytes_from_double(cb_auto_bit_converter *self,
												 double value,
												 uint8_t *out_buffer,
												 int32_t offset);

/* #endregion */
