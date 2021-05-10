#ifndef PSP2CLDR_COMMON_H
#define PSP2CLDR_COMMON_H

#include <stdint.h>

#define PSP2CLDR_STUB __attribute__((naked, weak))
#define UDF_TRAP __asm("udf #0")

#endif
