#ifndef PSP2CLDR_TLS_H
#define PSP2CLDR_TLS_H

#include <sys/psp2cldr_common.h>

#include <reent.h>

#define PSP2CLDR_TLS_SIZE 0x1000
typedef struct
{
    struct _reent reent;
} PSP2CLDR_TLS;

#endif
