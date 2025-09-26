#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#define __cb_force_inline inline __attribute__((always_inline))

#define __cb_weak __attribute__((weak))

#ifdef __cplusplus
}
#endif
