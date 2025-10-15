#pragma once
#include "cb/cb_define.h"
#include "cb/stream/cb_read_only_span.h"
#include "cb/stream/cb_span.h"
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
		/// @param span
		/// @return
		///
		template <typename ReturnType>
		ReturnType FromBytes(cb::ReadOnlySpan const &span)
		{
			__cb_assert(span.Size() == static_cast<int64_t>(sizeof(ReturnType)), "传入的 span 大小不符。");

			ReturnType ret;

			std::copy(span.Buffer(),
					  span.Buffer() + sizeof(ret),
					  reinterpret_cast<uint8_t *>(&ret));

			return ret;
		}

		///
		/// @brief 将指定类型对象序列化到字节缓冲区中。
		///
		/// @param value
		/// @param span
		/// @return
		///
		template <typename T>
		void GetBytes(T value, cb::Span const &span)
		{
			__cb_assert(span.Size() == static_cast<int64_t>(sizeof(T)), "传入的 span 大小不符。");

			uint8_t const *buffer = reinterpret_cast<uint8_t const *>(&value);

			std::copy(buffer,
					  buffer + sizeof(value),
					  span.Buffer());
		}

	} // namespace bit_converter
} // namespace cb
