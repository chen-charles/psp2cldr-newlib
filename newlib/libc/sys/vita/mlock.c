#include <sys/psp2cldr_internal.h>

#include <malloc.h>
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
