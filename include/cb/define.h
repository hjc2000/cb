#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

	// IWYU pragma: begin_keep

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

	// IWYU pragma: end_keep

#define __cb_force_inline inline __attribute__((always_inline))

#define __cb_weak __attribute__((weak))

#define CB_PAD_CAT(a, b) CB_PAD_CAT_(a, b)
#define CB_PAD_CAT_(a, b) a##b

#define __cb_padding_32(N) \
	uint32_t CB_PAD_CAT(__cb_padding_, __COUNTER__)[N]

#ifdef __cb_use_assert

	void cb_assert_block();

	#ifdef __cb_use_assert_print
		#define __cb_assert_print(...) fprintf(__VA_ARGS__)
	#else
		#define __cb_assert_print(...) ((void)0)
	#endif

	///
	/// @brief 断言
	///
	/// @param x 断言条件。
	/// @param message 断言失败时打印的消息。
	///
	#define __cb_assert(x, message)                    \
		do                                             \
		{                                              \
			if (!(x))                                  \
			{                                          \
				__cb_assert_print(stderr,              \
								  "%s, LINE %d, %s\n", \
								  __FILE__,            \
								  __LINE__,            \
								  (message));          \
                                                       \
				cb_assert_block();                     \
			}                                          \
		} while (false)

#else
	#define __cb_assert(x, message) ((void)0)
#endif

#ifdef __cplusplus
}
#endif
