#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>

#include "common.h"

int _execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

int _fork(void)
{
    errno = EAGAIN;
    return -1;
}

int _link(const char *old_, const char *new_)
{
    errno = ENOSYS;
    return -1;
}

int _unlink(const char *path)
{
    errno = ENOSYS;
    return -1;
}

int _readlink(const char *path, char *buf, size_t size)
{
    errno = ENOSYS;
    return -1;
}

int _getpid(void)
{
    return 42;
}

/* we will override those from psp2cldr, stubs are here to avoid linker complaints */
void PSP2CLDR_STUB _exit(int status) { UDF_TRAP; }
int PSP2CLDR_STUB _close(int file) { UDF_TRAP; }
int PSP2CLDR_STUB _fstat(int file, struct stat *st) { UDF_TRAP; }
int PSP2CLDR_STUB _kill(int pid, int sig) { UDF_TRAP; }
int PSP2CLDR_STUB _lseek(int file, int ptr, int dir) { UDF_TRAP; }
int PSP2CLDR_STUB _open(const char *name, int flags, int mode) { UDF_TRAP; }
int PSP2CLDR_STUB _read(int file, char *ptr, int len) { UDF_TRAP; }
char *PSP2CLDR_STUB _sbrk(int incr) { UDF_TRAP; }
int PSP2CLDR_STUB _stat(const char *file, struct stat *st) { UDF_TRAP; }
clock_t PSP2CLDR_STUB _times(struct tms *buf) { UDF_TRAP; }
int PSP2CLDR_STUB _wait(int *status) { UDF_TRAP; }
int PSP2CLDR_STUB _write(int file, char *ptr, int len) { UDF_TRAP; }
int PSP2CLDR_STUB _isatty(int fd) { UDF_TRAP; }
int PSP2CLDR_STUB _gettimeofday(struct timeval *ptimeval, void *ptimezone) { UDF_TRAP; }
