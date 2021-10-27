/* system function -- UNIX version */
#include <stdlib.h>
#include "yfuns.h"

        /* UNIX system calls */
int _Execve(const char *pathname, char *const argv[], char *const envp[]);

int _Fork(void);
int _Wait (int *);

int (system)(const char *s)
    {   /* send text to system command line processor */
    if (s)
        {   /* not just a test */
        int pid = _Fork();

        if (pid < 0)
            ;   /* fork failed */
        else if (pid == 0)
            {   /* continue here as child */
            char* argv[3] = {"sh", "-c", s};
            _Execve("/bin/sh", argv, NULL);
            exit(EXIT_FAILURE);
            }
        else    /* continue here as parent */
            while (_Wait(NULL) != pid)
                ;   /* wait for child */
        }
    return (-1);
    }
