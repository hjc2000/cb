#pragma once
#include "cb/bit/cb_endian.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus

namespace cb
{

}

#endif

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cb_auto_bit_converter
	{
		cb_endian_enum _remote_endian;
	} cb_auto_bit_converter;

	/* #region 私有函数 */

	bool __cb_auto_bit_converter_should_reverse__(cb_auto_bit_converter *self);

	/* #endregion */

	void cb_auto_bit_converter_initialize(cb_auto_bit_converter *self,
										  cb_endian_enum remote_endian);

	/* #region 转数字 */

	uint16_t cb_auto_bit_converter_byte_array_to_uint16(cb_auto_bit_converter *self,
														uint8_t const *buffer);

	int16_t cb_auto_bit_converter_byte_array_to_int16(cb_auto_bit_converter *self,
													  uint8_t const *buffer);

	uint32_t cb_auto_bit_converter_byte_array_to_uint32(cb_auto_bit_converter *self,
														uint8_t const *buffer);

	int32_t cb_auto_bit_converter_byte_array_to_int32(cb_auto_bit_converter *self,
													  uint8_t const *buffer);

	uint64_t cb_auto_bit_converter_byte_array_to_uint64(cb_auto_bit_converter *self,
														uint8_t const *buffer);

	int64_t cb_auto_bit_converter_byte_array_to_int64(cb_auto_bit_converter *self,
													  uint8_t const *buffer);

	float cb_auto_bit_converter_byte_array_to_float(cb_auto_bit_converter *self,
													uint8_t const *buffer);

	double cb_auto_bit_converter_byte_array_to_double(cb_auto_bit_converter *self,
													  uint8_t const *buffer);

	/* #endregion */

	/* #region 转字节数组 */

	void cb_auto_bit_converter_get_bytes_from_uint16(cb_auto_bit_converter *self,
													 uint16_t value,
													 uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_int16(cb_auto_bit_converter *self,
													int16_t value,
													uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_uint32(cb_auto_bit_converter *self,
													 uint32_t value,
													 uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_int32(cb_auto_bit_converter *self,
													int32_t value,
													uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_uint64(cb_auto_bit_converter *self,
													 uint64_t value,
													 uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_int64(cb_auto_bit_converter *self,
													int64_t value,
													uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_float(cb_auto_bit_converter *self,
													float value,
													uint8_t *out_buffer);

	void cb_auto_bit_converter_get_bytes_from_double(cb_auto_bit_converter *self,
													 double value,
													 uint8_t *out_buffer);

	/* #endregion */

#ifdef __cplusplus
}
#endif
