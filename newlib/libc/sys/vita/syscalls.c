#include <errno.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/wait.h>

#include "common.h"

int _execve(const char *__path, char *const __argv[], char *const __envp[])
{
    errno = ENOMEM;
    return -1;
}

pid_t _fork(void)
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

pid_t _getpid(void)
{
    return 42;
}

/* we will override those from psp2cldr, stubs are here to avoid linker complaints */
void PSP2CLDR_STUB _exit(int status) { UDF_TRAP; }
int PSP2CLDR_STUB _close(int __fildes) { UDF_TRAP; }
int PSP2CLDR_STUB _fstat(int file, struct stat *st) { UDF_TRAP; }
int PSP2CLDR_STUB _kill(int pid, int sig) { UDF_TRAP; }
_off_t PSP2CLDR_STUB _lseek(int __fildes, _off_t __offset, int __whence) { UDF_TRAP; }
int PSP2CLDR_STUB _open(const char *name, int flags, int mode) { UDF_TRAP; }
_READ_WRITE_RETURN_TYPE PSP2CLDR_STUB _read(int __fd, void *__buf, size_t __nbyte) { UDF_TRAP; }
void *PSP2CLDR_STUB _sbrk(ptrdiff_t __incr) { UDF_TRAP; }
int PSP2CLDR_STUB _stat(const char *file, struct stat *st) { UDF_TRAP; }
clock_t PSP2CLDR_STUB _times(struct tms *buf) { UDF_TRAP; }
pid_t PSP2CLDR_STUB _wait(int *status) { UDF_TRAP; }
_READ_WRITE_RETURN_TYPE PSP2CLDR_STUB _write(int __fd, const void *__buf, size_t __nbyte) { UDF_TRAP; }
int PSP2CLDR_STUB _isatty(int fd) { UDF_TRAP; }
int PSP2CLDR_STUB _gettimeofday(struct timeval *__p, void *__tz) { UDF_TRAP; }

#include "psp2cldr_internals.h"

void __malloc_lock(struct _reent *reent)
{
    __psp2cldr__internal_call_sym("__malloc_lock");
}

void __malloc_unlock(struct _reent *reent)
{
    __psp2cldr__internal_call_sym("__malloc_unlock");
}

#include <envlock.h>
void __env_lock(struct _reent *reent)
{
    __psp2cldr__internal_call_sym("__env_lock");
}

void __env_unlock(struct _reent *reent)
{
    __psp2cldr__internal_call_sym("__env_unlock");
}
