#pragma once
#include "cb/define.h"
#include "cb/stream/ReadOnlySpan.h"
#include "cb/stream/Span.h"
#include <algorithm>
#include <cstdint>

namespace cb
{
	namespace bit_converte
	{
		///
		/// @brief 从字节缓冲区中反序列化出指定类型对象。
		///
		/// @param span
		/// @return
		///
		template <typename ReturnType>
		ReturnType FromBytes(cb::ReadOnlySpan const &span)
		{
			__cb_assert(span.Size() == static_cast<int64_t>(sizeof(ReturnType)), "传入的 span 大小不符。");

			struct
			{
				// 使用普通字节缓冲区，避免 ReturnType 的构造函数被调用。
				alignas(ReturnType) uint8_t _buffer[sizeof(ReturnType)];
			} buffer_provider;

			std::copy(span.Buffer(),
					  span.Buffer() + sizeof(ReturnType),
					  buffer_provider._buffer);

			return *reinterpret_cast<ReturnType *>(buffer_provider._buffer);
		}

		///
		/// @brief 将指定类型对象序列化到字节缓冲区中。
		///
		/// @param value
		/// @param span
		/// @return
		///
		template <typename ValueType>
		void GetBytes(ValueType value, cb::Span const &span)
		{
			__cb_assert(span.Size() == static_cast<int64_t>(sizeof(ValueType)), "传入的 span 大小不符。");

			uint8_t const *value_buffer = reinterpret_cast<uint8_t const *>(&value);

			std::copy(value_buffer,
					  value_buffer + sizeof(ValueType),
					  span.Buffer());
		}

	} // namespace bit_converte
} // namespace cb
