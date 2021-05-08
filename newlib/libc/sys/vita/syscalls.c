#include <errno.h>
#include <reent.h>

#include "psp2cldr_internals.h"
#define PSP2CLDR_NAKED __attribute__((naked))
#define UDF_TRAP __asm("udf #0")

typedef struct
{
    struct _reent reent;
} ThreadLocalStorage;

int __psp2cldr_init_newlib(void)
{
    /* __getreent currently doesn't know what to return */
    ThreadLocalStorage *tls = __psp2cldr__internal_tls_ctrl(0);
    _REENT_INIT_PTR(&tls->reent);
    return 0;
}

int __psp2cldr_fini_newlib(void)
{
    __psp2cldr__internal_tls_ctrl(1);
    return 0;
}

struct _reent *__getreent(void)
{
    ThreadLocalStorage *tls = __psp2cldr__internal_tls_ctrl(0);
    return &tls->reent;
}

void *PSP2CLDR_NAKED __psp2cldr__internal_tls_ctrl(uint32_t ctrl) { UDF_TRAP; }

#include <sys/stat.h>
#include <sys/times.h>

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
void PSP2CLDR_NAKED _exit(int status) { UDF_TRAP; }
int PSP2CLDR_NAKED _close(int file) { UDF_TRAP; }
int PSP2CLDR_NAKED _fstat(int file, struct stat *st) { UDF_TRAP; }
int PSP2CLDR_NAKED _kill(int pid, int sig) { UDF_TRAP; }
int PSP2CLDR_NAKED _lseek(int file, int ptr, int dir) { UDF_TRAP; }
int PSP2CLDR_NAKED _open(const char *name, int flags, int mode) { UDF_TRAP; }
int PSP2CLDR_NAKED _read(int file, char *ptr, int len) { UDF_TRAP; }
char *PSP2CLDR_NAKED _sbrk(int incr) { UDF_TRAP; }
int PSP2CLDR_NAKED _stat(const char *file, struct stat *st) { UDF_TRAP; }
clock_t PSP2CLDR_NAKED _times(struct tms *buf) { UDF_TRAP; }
int PSP2CLDR_NAKED _wait(int *status) { UDF_TRAP; }
int PSP2CLDR_NAKED _write(int file, char *ptr, int len) { UDF_TRAP; }
int PSP2CLDR_NAKED _isatty(int fd) { UDF_TRAP; }
int PSP2CLDR_NAKED _gettimeofday(struct timeval *ptimeval, void *ptimezone) { UDF_TRAP; }
