#ifndef _OS_LIBC_H_
#define _OS_LIBC_H_

#include "ultratypes.h"

#ifdef OSX_BUILD
#include <strings.h> // OSX doesn't like it not being included?
#elif

// there's no way that shit's defined, use memcpy/memset
#include <string.h>

#undef bzero
#undef bcopy
#define bzero(buf, len) memset((buf), 0, (len))
#define bcopy(src, dst, len) memcpy((dst), (src), (len))

#else

extern void bcopy(const void *, void *, size_t);
extern void bzero(void *, size_t);

#endif

#endif /* !_OS_LIBC_H_ */
