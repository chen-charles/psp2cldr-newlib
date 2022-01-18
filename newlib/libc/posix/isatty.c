/* isatty.c */

#if 0 // conflicts with sysisatty's version

#include <unistd.h>
#include <reent.h>

int
isatty (int fd)
{
  return _isatty (fd);
}

#endif
