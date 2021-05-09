#ifndef PSP2CLDR_COMMON_H
#define PSP2CLDR_COMMON_H

#define PSP2CLDR_STUB __attribute__((naked, weak))
#define UDF_TRAP __asm("udf #0")

#include <reent.h>
typedef struct
{
    struct _reent reent;
} ThreadLocalStorage;

#endif
