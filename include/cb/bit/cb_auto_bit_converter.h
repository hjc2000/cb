#pragma once
#include "cb/bit/cb_endian.h"
#include "cb_bit_converter.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus

	#include <algorithm>

namespace cb
{
	namespace bit_converter
	{
		class AutoBitConverter
		{
		private:
			cb::endian::Endian _remote_endian{};

			constexpr bool ShouldReverse() const
			{
				return cb::endian::NativeEndian() != _remote_endian;
			}

		public:
			constexpr AutoBitConverter(cb::endian::Endian remote_endian)
			{
				_remote_endian = remote_endian;
			}

			///
			/// @brief 从字节缓冲区中反序列化出对象。
			///
			/// @note 会自动根据本机字节序和远端字节序进行字节序转换。
			///
			/// @param buffer
			/// @return
			///
			template <typename ReturnType>
			ReturnType FromByte(uint8_t const *buffer) const
			{
				ReturnType ret = cb::bit_converter::FromBytes<ReturnType>(buffer);

				if (ShouldReverse())
				{
					uint8_t *p = reinterpret_cast<uint8_t *>(&ret);
					std::reverse(p, p + sizeof(ReturnType));
				}

				return ret;
			}

			///
			/// @brief 将对象序列化到字节缓冲区中。
			///
			/// @note 会自动根据本机字节序和远端字节序进行字节序转换。
			///
			/// @param value
			/// @param out_buffer
			/// @return
			///
			template <typename ValueType>
			void GetBytes(ValueType value, uint8_t *out_buffer) const
			{
				cb::bit_converter::GetBytes<ValueType>(value, out_buffer);

				if (ShouldReverse())
				{
					std::reverse(out_buffer, out_buffer + sizeof(ValueType));
				}
			}
		};

		constexpr cb::bit_converter::AutoBitConverter big_endian_remote_converter{cb::endian::Endian::BigEndian};

		constexpr cb::bit_converter::AutoBitConverter little_endian_remote_converter{cb::endian::Endian::LittleEndian};

	} // namespace bit_converter
} // namespace cb

#endif

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cb_auto_bit_converter
	{
		cb_endian_enum _remote_endian;
	} cb_auto_bit_converter;

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
