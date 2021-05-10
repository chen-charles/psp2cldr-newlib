#ifndef PSP2CLDR_INTERNAL_H
#define PSP2CLDR_INTERNAL_H

#include <sys/psp2cldr_common.h>

/* internal routines provided by psp2cldr prior to loading, see psp2cldr's docs. for their usages */

void *PSP2CLDR_STUB __psp2cldr__internal_tls_ctrl(uint32_t ctrl); // see sys/psp2cldr_tls.h

int PSP2CLDR_STUB __psp2cldr__internal_call_nid(uint32_t libraryNID, uint32_t functionNID, ...);
int PSP2CLDR_STUB __psp2cldr__internal_call_sym(const char *target, ...);

#endif
