#pragma once

// IWYU pragma: begin_keep

#include <stdint.h>

// IWYU pragma: end_keep

#ifdef __cplusplus
extern "C"
{
#endif

#define __cb_force_inline inline __attribute__((always_inline))

#define __cb_weak __attribute__((weak))

#define CB_PAD_CAT(a, b) CB_PAD_CAT_(a, b)
#define CB_PAD_CAT_(a, b) a##b
#define __cb_padding(N) \
	uint32_t CB_PAD_CAT(__cb_padding_, __COUNTER__)[N]

#ifdef __cplusplus
}
#endif
