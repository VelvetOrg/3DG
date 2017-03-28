#pragma once

/* is inline supported? C99? */
#if __STDC_VERSION__ >= 199901L || defined(__cplusplus) || defined(_MSC_VER)
#define INLINE inline
#else
#define INLINE

#endif // __STDC_VERSION__...