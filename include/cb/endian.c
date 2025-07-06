#include "endian.h"
#include <stdint.h>

cb_endian_enum cb_local_host_endian()
{
	uint32_t a = 1;
	uint8_t *p = (uint8_t *)(&a);
	if (p[0])
	{
		return cb_endian_little_endian;
	}

	return cb_endian_big_endian;
}
