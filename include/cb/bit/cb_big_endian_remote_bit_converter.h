#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/* #region 转数字 */

	uint16_t cb_big_endian_remote_bit_converter_byte_array_to_uint16(uint8_t const *buffer);

	int16_t cb_big_endian_remote_bit_converter_byte_array_to_int16(uint8_t const *buffer);

	uint32_t cb_big_endian_remote_bit_converter_byte_array_to_uint32(uint8_t const *buffer);

	int32_t cb_big_endian_remote_bit_converter_byte_array_to_int32(uint8_t const *buffer);

	uint64_t cb_big_endian_remote_bit_converter_byte_array_to_uint64(uint8_t const *buffer);

	int64_t cb_big_endian_remote_bit_converter_byte_array_to_int64(uint8_t const *buffer);

	float cb_big_endian_remote_bit_converter_byte_array_to_float(uint8_t const *buffer);

	double cb_big_endian_remote_bit_converter_byte_array_to_double(uint8_t const *buffer);

	/* #endregion */

	/* #region 转字节数组 */

	void cb_big_endian_remote_bit_converter_get_bytes_from_uint16(
		uint16_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_int16(
		int16_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_uint32(
		uint32_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_int32(
		int32_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_uint64(
		uint64_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_int64(
		int64_t value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_float(
		float value,
		uint8_t *out_buffer);

	void cb_big_endian_remote_bit_converter_get_bytes_from_double(
		double value,
		uint8_t *out_buffer);

	/* #endregion */

#ifdef __cplusplus
}
#endif
