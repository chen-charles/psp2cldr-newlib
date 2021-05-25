#include <sys/psp2cldr_internal.h>

void PSP2CLDR_STUB __psp2cldr__internal_panic(const char *reason) { UDF_TRAP; }

uint32_t PSP2CLDR_STUB __psp2cldr__internal_tls_alloc() { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_tls_free(uint32_t key) { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_tls_setvalue(uint32_t key, const void *value) { UDF_TRAP; }
void *PSP2CLDR_STUB __psp2cldr__internal_tls_getvalue(uint32_t key) { UDF_TRAP; }

void *PSP2CLDR_STUB __psp2cldr__internal_mmap(uint32_t length) { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_munmap(void *addr, uint32_t length) { UDF_TRAP; }

int PSP2CLDR_STUB __psp2cldr__internal_call_nid(uint32_t libraryNID, uint32_t functionNID, ...) { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_call_sym(const char *target, ...) { UDF_TRAP; }
