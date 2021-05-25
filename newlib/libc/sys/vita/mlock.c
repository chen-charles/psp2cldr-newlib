#include <sys/psp2cldr_internal.h>

#include <malloc.h>
void __malloc_lock(struct _reent *reent)
{
    UDF_TRAP;
}

void __malloc_unlock(struct _reent *reent)
{
    UDF_TRAP;
}

#include <envlock.h>
void __env_lock(struct _reent *reent)
{
    UDF_TRAP;
}

void __env_unlock(struct _reent *reent)
{
    UDF_TRAP;
}
