/* limits.h standard header -- x64 version */
#ifndef _LIMITS
#define _LIMITS
#ifndef _YVALS
#include <yvals.h>
#endif
        /* char properties */
#define CHAR_BIT    8

#define is_type_signed(my_type) (((my_type)-1) < 0)

#if is_type_signed(char)
#define CHAR_MAX    127
#define CHAR_MIN    (-127-_C2)
#else
#define CHAR_MAX    255
#define CHAR_MIN    0
#endif
        /* int properties */
#define INT_MAX     2147483647
#define INT_MIN     (-2147483647-_C2)
#define UINT_MAX    4294967295U
        /* long properties */
#define LONG_MAX    9223372036854775807
#define LONG_MIN    (-2147483647-_C2)
        /* multibyte properties */
#define MB_LEN_MAX  16
        /* signed char properties */
#define SCHAR_MAX   127
#define SCHAR_MIN   (-127-_C2)
        /* short properties */
#define SHRT_MAX    32767
#define SHRT_MIN    (-32767-_C2)
        /* unsigned properties */
#define UCHAR_MAX   255
#define ULONG_MAX   18446744073709551615
#define USHRT_MAX   65535U
#endif
