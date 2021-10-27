#include "yfuns.h"

const char **environ;

time_t _time(time_t *tloc) {
  struct timeval tv;

    int ret = gettimeofday(&tv, NULL);

    if (ret < 0) {
        SET_ERRNO(-ret);
        return -1;
    }

    return tv.tv_sec;
}

pid_t fork(void)
{
    pid_t ret = sys_fork();

    if (ret < 0) {
        SET_ERRNO(-ret);
        ret = -1;
    }
    return ret;
}

asm(".section .text\n"
    ".global _start\n"
    "_start:\n"
    "pop %rdi\n"                // argc   (first arg, %rdi)
    "mov %rsp, %rsi\n"          // argv[] (second arg, %rsi)
    "lea 8(%rsi,%rdi,8),%rdx\n" // then a NULL then envp (third arg, %rdx)
    "and $-16, %rsp\n"          // x86 ABI : esp must be 16-byte aligned when
    "sub $8, %rsp\n"            // entering the callee
    "call main\n"               // main() returns the status code, we'll exit with it.
    "movzb %al, %rdi\n"         // retrieve exit code from 8 lower bits
    "mov $60, %rax\n"           // NR_exit == 60
    "syscall\n"                 // really exit
    "hlt\n"                     // ensure it does not return
    "");
