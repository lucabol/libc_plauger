/* time function -- UNIX version */
#include <time.h>
#include "yfuns.h"

time_t (time)(time_t *tod)
    {   /* return calendar time */
    time_t t = _Time(NULL) + (70*365LU+17)*86400;

    if (tod)
        *tod = t;
    return (t);
    }
