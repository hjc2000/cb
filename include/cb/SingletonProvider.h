#pragma once
#include <cstdint> // IWYU pragma: keep
#include <new>     // IWYU pragma: keep

namespace cb
{
	template <typename T>
	class SingletonProvider
	{
	private:
		bool _initialized = false;
		alignas(T) uint8_t _instance_buffer[sizeof(T)];

		T &get_instance()
		{
			if (!_initialized)
			{
				new (_instance_buffer) T{};
				_initialized = true;
			}

			return *reinterpret_cast<T *>(_instance_buffer);
		}

	public:
		///
		/// @brief 获取单例。
		///
		/// @return
		///
		T &Instance()
		{
			return get_instance();
		}
	};

} // namespace cb
