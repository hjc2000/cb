#pragma once
#include <cstdint>

namespace cb
{
	class IncrementGuard
	{
	private:
		int32_t _value = 0;

	public:
		IncrementGuard(int32_t &value)
			: _value{value}
		{
		}

		~IncrementGuard()
		{
			_value++;
		}
	};

} // namespace cb
