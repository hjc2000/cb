#include "endian.h"
#include <cstdint>

namespace
{
	class EndianProvider
	{
	private:
		union IntegerUnion
		{
			uint32_t u32;
			uint8_t u8[4];
		};

		IntegerUnion _union{};

	public:
		constexpr EndianProvider()
		{
			_union.u32 = 1;
		}

		constexpr cb_endian_enum NativeEndian() const
		{
			if (_union.u8[0])
			{
				return cb_endian_little_endian;
			}

			return cb_endian_big_endian;
		}
	};

	constexpr EndianProvider _provider{};

} // namespace

cb_endian_enum const cb_native_endian = _provider.NativeEndian();
