#pragma once
#include <stdint.h>

#ifdef __cplusplus

	#include <algorithm>
	#include <cstdint>

namespace cb
{
	namespace bit_converter
	{
		///
		/// @brief 从字节缓冲区中反序列化出指定类型对象。
		///
		/// @param buffer
		/// @return
		///
		template <typename ReturnType>
		ReturnType FromBytes(uint8_t const *buffer)
		{
			ReturnType ret;

			std::copy(buffer,
					  buffer + sizeof(ret),
					  reinterpret_cast<uint8_t *>(&ret));

			return ret;
		}

		///
		/// @brief 将指定类型对象序列化到字节缓冲区中。
		///
		/// @param value
		/// @param out_buffer
		/// @return
		///
		template <typename T>
		void GetBytes(T value, uint8_t *out_buffer)
		{
			uint8_t const *buffer = reinterpret_cast<uint8_t const *>(&value);

			std::copy(buffer,
					  buffer + sizeof(value),
					  out_buffer);
		}

	} // namespace bit_converter
} // namespace cb

#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif

	/* #region 转数字 */

	///
	/// @brief 从字节数组中反序列化得到 uint16_t.
	///
	/// @param buffer
	/// @return
	///
	uint16_t cb_bit_converter_byte_array_to_uint16(uint8_t const *buffer);

	///
	/// @brief 从字节数组中反序列化得到 int16_t.
	///
	/// @param buffer
	/// @return
	///
	int16_t cb_bit_converter_byte_array_to_int16(uint8_t const *buffer);

	///
	/// @brief 把高字节和低字节拼接成 uint16_t.
	///
	/// @param high
	/// @param low
	/// @return
	///
	uint16_t cb_bit_converter_2_byte_to_uint16(uint8_t high, uint8_t low);

	///
	/// @brief 从字节数组中反序列化得到 uint32_t.
	///
	/// @param buffer
	/// @return
	///
	uint32_t cb_bit_converter_byte_array_to_uint32(uint8_t const *buffer);

	///
	/// @brief 从字节数组中反序列化得到 int32_t.
	///
	/// @param buffer
	/// @return
	///
	int32_t cb_bit_converter_byte_array_to_int32(uint8_t const *buffer);

	///
	/// @brief 把高 uint16_t 和低 uint16_t 拼接成 uint32_t.
	///
	/// @param high
	/// @param low
	/// @return
	///
	uint32_t cb_bit_converter_2_uint16_to_uint32(uint16_t high, uint16_t low);

	///
	/// @brief 把 4 个字节拼接成 uint32_t.
	///
	/// @param b3
	/// @param b2
	/// @param b1
	/// @param b0
	/// @return
	///
	uint32_t cb_bit_converter_4_byte_to_uint32(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0);

	///
	/// @brief 从字节数组中反序列化得到 uint64_t.
	///
	/// @param buffer
	/// @return
	///
	uint64_t cb_bit_converter_byte_array_to_uint64(uint8_t const *buffer);

	///
	/// @brief 从字节数组中反序列化得到 int64_t.
	///
	/// @param buffer
	/// @return
	///
	int64_t cb_bit_converter_byte_array_to_int64(uint8_t const *buffer);

	///
	/// @brief 从字节数组中反序列化得到 float.
	///
	/// @param buffer
	/// @return
	///
	float cb_bit_converter_byte_array_to_float(uint8_t const *buffer);

	///
	/// @brief 从字节数组中反序列化得到 double.
	///
	/// @param buffer
	/// @return
	///
	double cb_bit_converter_byte_array_to_double(uint8_t const *buffer);

	/* #endregion */

	/* #region 转字节数组 */

	void cb_bit_converter_get_bytes_from_uint16(uint16_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_int16(int16_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_uint32(uint32_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_int32(int32_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_uint64(uint64_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_int64(int64_t value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_float(float value, uint8_t *out_buffer);

	void cb_bit_converter_get_bytes_from_double(double value, uint8_t *out_buffer);

	/* #endregion */

#ifdef __cplusplus
}
#endif
