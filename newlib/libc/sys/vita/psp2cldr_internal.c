#include <sys/psp2cldr_internal.h>

void *PSP2CLDR_STUB __psp2cldr__internal_tls_ctrl(uint32_t ctrl) { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_call_nid(uint32_t libraryNID, uint32_t functionNID, ...) { UDF_TRAP; }
int PSP2CLDR_STUB __psp2cldr__internal_call_sym(const char *target, ...) { UDF_TRAP; }
