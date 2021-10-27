/* _Getmem function */
#include "xalloc.h"
#include "yfuns.h"

void *_Getmem(size_t size)
    {   /* allocate raw storage */
    void *p;
    int isize = size;

    return (isize <= 0 || (p = sbrk(isize)) == (void *)-1
        ? NULL : p);
    }
