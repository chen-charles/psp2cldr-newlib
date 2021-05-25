#ifndef PSP2CLDR_INTERNAL_H
#define PSP2CLDR_INTERNAL_H

#include <sys/psp2cldr_common.h>

/* internal routines provided by psp2cldr prior to loading, see psp2cldr's docs. for their usages */

void PSP2CLDR_STUB __psp2cldr__internal_panic(const char *reason);

uint32_t PSP2CLDR_STUB __psp2cldr__internal_tls_alloc();
int PSP2CLDR_STUB __psp2cldr__internal_tls_free(uint32_t key);
int PSP2CLDR_STUB __psp2cldr__internal_tls_setvalue(uint32_t key, const void *value);
void *PSP2CLDR_STUB __psp2cldr__internal_tls_getvalue(uint32_t key);

void *PSP2CLDR_STUB __psp2cldr__internal_mmap(uint32_t length);
int PSP2CLDR_STUB __psp2cldr__internal_munmap(void *addr, uint32_t length);

int PSP2CLDR_STUB __psp2cldr__internal_call_nid(uint32_t libraryNID, uint32_t functionNID, ...);
int PSP2CLDR_STUB __psp2cldr__internal_call_sym(const char *target, ...);

#endif
