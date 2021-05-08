#ifndef PSP2CLDR_INTERNAL_H
#define PSP2CLDR_INTERNAL_H

#include <stdint.h>

/* internal routines provided by psp2cldr prior to loading, see psp2cldr's docs. for their usages */

void *__attribute__((naked)) __psp2cldr__internal_tls_ctrl(uint32_t ctrl); // tls has a size of 0x1000

#endif
