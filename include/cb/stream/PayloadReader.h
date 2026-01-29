#pragma once
#include "cb/bit/AutoBitConverter.h"
#include "cb/bit/Endian.h"
#include "cb/stream/ReadOnlySpan.h"
#include "cb/stream/Span.h"
#include <cstdint>

namespace cb
{
	class PayloadReader
	{
	private:
		cb::ReadOnlySpan _span{};
		int64_t _position = 0;

	public:
		PayloadReader(cb::ReadOnlySpan const &span)
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
		/// @brief 读取载荷数据。
		///
		/// @param span
		///
		void ReadPayload(cb::Span const &span)
		{
			cb::Range range_to_read{
				_position,
				_position + span.Size(),
			};

			cb::ReadOnlySpan span_to_read = _span[range_to_read];
			span.CopyFrom(span_to_read);
			_position += span_to_read.Size();
		}

		///
		/// @brief 读取载荷数据。
		///
		/// @param remote_endian
		///
		/// @return
		///
		template <typename ReturnType>
		ReturnType ReadPayload(cb::endian::Endian remote_endian)
		{
			cb::Range range_to_read{
				_position,
				_position + static_cast<int64_t>(sizeof(ReturnType)),
			};

			cb::ReadOnlySpan span_to_read = _span[range_to_read];

			cb::AutoBitConverter conveter{remote_endian};
			ReturnType ret = conveter.FromBytes<ReturnType>(span_to_read);

			_position += span_to_read.Size();
			return ret;
		}
	};

} // namespace cb
