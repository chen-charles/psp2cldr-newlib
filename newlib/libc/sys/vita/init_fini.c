#include "common.h"
#include "psp2cldr_internals.h"

int _init_signal(void);

int __psp2cldr_init_newlib(void)
{
    /* __getreent currently doesn't know what to return */
    ThreadLocalStorage *tls = __psp2cldr__internal_tls_ctrl(0);
    _REENT_INIT_PTR(&tls->reent);
    /* malloc and all other utilities are now up */

    return _init_signal();
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
