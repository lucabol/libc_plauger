/* stddef.h standard header */
#ifndef _STDDEF
#define _STDDEF
#ifndef _YVALS
#include <yvals.h>
#endif
        /* macros */
#define NULL    _NULL
#define offsetof(type, member) ((size_t)( (char *)&(((type *)0)->member) - (char *)0 ))

/* type definitions */
#ifndef _SIZET
#define _SIZET
typedef _Sizet size_t;
#endif
#ifndef _WCHART
#define _WCHART
typedef _Wchart wchar_t;
#endif
typedef _Ptrdifft ptrdiff_t;
#endif
