/* yfuns.h functions header -- UNIX version */
#ifndef _YFUNS
#define _YFUNS

#include "nolibc.h"

        /* process control functions */
#define _Envp   (*environ)
#define _Time   _time
#define _Exit(status)   _exit(status)
#define _Fork fork
#define _Execve execve
#define _Wait wait
        /* stdio functions */
#define _Fclose(str)    close((str)->_Handle)
#define _Fread(str, buf, cnt)   read((str)->_Handle, buf, cnt)
#define _Fwrite(str, buf, cnt)  write((str)->_Handle, buf, cnt)
        /* interface declarations */
extern const char **environ;
time_t _time(time_t *tloc);

/*
int close(int);
void _exit(int);
int read(int, unsigned char *, int);
int write(int, const unsigned char *, int);
*/
#endif
