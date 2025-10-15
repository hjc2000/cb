#pragma once
#include "cb/bit/cb_endian.h"
#include "cb/stream/cb_read_only_span.h"
#include "cb/stream/cb_span.h"
#include "cb_bit_converte.h"
#include <algorithm>
#include <stdbool.h>
#include <stdint.h>

namespace cb
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
		/// @param span
		/// @return
		///
		template <typename ReturnType>
		ReturnType FromBytes(cb::ReadOnlySpan const &span) const
		{
			ReturnType ret = cb::bit_converte::FromBytes<ReturnType>(span);

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
		/// @param span
		/// @return
		///
		template <typename ValueType>
		void GetBytes(ValueType value, cb::Span const &span) const
		{
			cb::bit_converte::GetBytes<ValueType>(value, span);

			if (ShouldReverse())
			{
				std::reverse(span.Buffer(), span.Buffer() + sizeof(ValueType));
			}
		}
	};

	constexpr cb::AutoBitConverter big_endian_remote_converter{cb::endian::Endian::BigEndian};

	constexpr cb::AutoBitConverter little_endian_remote_converter{cb::endian::Endian::LittleEndian};

} // namespace cb
