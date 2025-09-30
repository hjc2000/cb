#pragma once
#include <algorithm>
#include <cstdint>
#include <stdint.h>

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
