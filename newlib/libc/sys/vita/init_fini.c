#include <pthread.h>

#include <string.h>
#include <sys/psp2cldr_internal.h>

int _reent_key_initialized = 0;
uint32_t _reent_tls_key;

extern void exit(int);
int _init_signal(void);
void __psp2cldr_init_newlib(void)
{
    if (_reent_key_initialized == 0)
    {
        _reent_tls_key = __psp2cldr__internal_tls_alloc();
        _reent_key_initialized = 1;
    }

    /* __getreent currently doesn't know what to return */
    if (__psp2cldr__internal_tls_getvalue(_reent_tls_key) == NULL)
    {
        struct _reent *p_reent = __psp2cldr__internal_mmap(0x1000);
        _REENT_INIT_PTR(p_reent);
        __psp2cldr__internal_tls_setvalue(_reent_tls_key, p_reent);
    }
    else
    {
        __psp2cldr__internal_panic("__psp2cldr_init_newlib is called more than once for this thread");
    }

    /* malloc and all other utilities are now up */

    /* run per-thread init functions */
    if (_init_signal() != 0)
    {
        __psp2cldr__internal_panic("_init_signal failed");
    }
}

void __psp2cldr_fini_newlib(void)
{
    struct _reent *p_reent = __psp2cldr__internal_tls_getvalue(_reent_tls_key);
    if (p_reent == NULL)
        __psp2cldr__internal_panic("__psp2cldr_fini_newlib called when reent in tls is NULL");
    __psp2cldr__internal_tls_setvalue(_reent_tls_key, NULL);
    __psp2cldr__internal_munmap(p_reent, 0x1000);
}

struct _reent *__getreent(void)
{
    struct _reent *p_reent = __psp2cldr__internal_tls_getvalue(_reent_tls_key);
    if (p_reent == NULL)
        __psp2cldr__internal_panic("__getreent called when reent in tls is NULL");
    return p_reent;
}
