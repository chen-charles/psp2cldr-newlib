#include <pthread.h>

#include <sys/psp2cldr_internal.h>
#include <sys/psp2cldr_tls.h>

#include <string.h>

extern void exit(int);
int _init_signal(void);
void __psp2cldr_init_newlib(void)
{
    /* __getreent currently doesn't know what to return */
    PSP2CLDR_TLS *tls = __psp2cldr__internal_tls_ctrl(0);
    memset(tls, 0, PSP2CLDR_TLS_SIZE);
    _REENT_INIT_PTR(&tls->reent);

    /* malloc and all other utilities are now up */

    /* run per-thread init functions */
    if (_init_signal() != 0)
    {
        exit(0x12345678);
    }
}

void __psp2cldr_fini_newlib(void)
{
    __psp2cldr__internal_tls_ctrl(1);
}

struct _reent *__getreent(void)
{
    PSP2CLDR_TLS *tls = __psp2cldr__internal_tls_ctrl(0);
    return &tls->reent;
}
