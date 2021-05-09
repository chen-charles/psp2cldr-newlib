#include "common.h"
#include "psp2cldr_internals.h"

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
