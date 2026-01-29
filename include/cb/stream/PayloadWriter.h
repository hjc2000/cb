#pragma once
#include "cb/bit/AutoBitConverter.h"
#include "cb/bit/Endian.h"
#include "cb/stream/Span.h"
#include <cstdint>

namespace cb
{
	class PayloadWriter
	{
	private:
		cb::Span _span{};
		int64_t _position = 0;

	public:
		PayloadWriter(cb::Span const &span)
			: _span{span}
		{
		}

		int64_t Position() const
		{
			return _position;
		}

		void ResetPosition()
		{
			_position = 0;
		}

		///
		/// @brief 写入载荷。
		///
		/// @param span
		///
		void WritePayload(cb::ReadOnlySpan const &span)
		{
			cb::Range range{
				_position,
				_position + span.Size(),
			};

			cb::Span span_to_write = _span[range];
			span_to_write.CopyFrom(span);

			_position += span_to_write.Size();
		}

		///
		/// @brief 写入载荷。
		///
		/// @param value
		/// @param remote_endian
		///
		template <typename ValueType>
		void WritePayload(ValueType value, cb::endian::Endian remote_endian)
		{
			cb::Range range{
				_position,
				_position + static_cast<int64_t>(sizeof(ValueType)),
			};

			cb::Span span_to_write = _span[range];

			cb::AutoBitConverter conveter{remote_endian};
			conveter.GetBytes(value, span_to_write);

			_position += span_to_write.Size();
		}
	};

} // namespace cb
