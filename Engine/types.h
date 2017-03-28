#ifndef _TYPES_H
#define _TYPES_H

//TODO: Create wide int without cstdint
#include <stdint.h>

/* fixed width integers */
typedef uint8_t		byte_t;
typedef uint32_t	dword_t;
typedef uint16_t	word_t;
typedef intmax_t	max_t;
typedef uintmax_t	umax_t;

/* is inline supported? C99? */
#if __STDC_VERSION__ >= 199901L || defined(__cplusplus)
#define INLINE inline
#else
#define INLINE
#endif // __STDC_VERSION__...

#endif // !_TYPES_H