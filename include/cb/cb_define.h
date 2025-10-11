#pragma once

// IWYU pragma: begin_keep

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// IWYU pragma: end_keep

#ifdef __cplusplus
extern "C"
{
#endif

#define __cb_force_inline inline __attribute__((always_inline))

#define __cb_weak __attribute__((weak))

#define CB_PAD_CAT(a, b) CB_PAD_CAT_(a, b)
#define CB_PAD_CAT_(a, b) a##b
#define __cb_padding_32(N) \
	uint32_t CB_PAD_CAT(__cb_padding_, __COUNTER__)[N]

#ifdef __cb_use_assert

	void cb_assert_block();

	///
	/// @brief 断言
	///
	/// @param x 断言条件。
	/// @param message 断言失败时打印的消息。
	///
	#define __cb_assert(x, message)          \
		do                                   \
		{                                    \
			if (!(x))                        \
			{                                \
				fprintf(stderr,              \
						"%s, LINE %d, %s\n", \
						__FILE__,            \
						__LINE__,            \
						(message));          \
                                             \
				cb_assert_block();           \
			}                                \
		} while (false)

#else
	#define __cb_assert(x, message)
#endif

#ifdef __cplusplus
}
#endif
