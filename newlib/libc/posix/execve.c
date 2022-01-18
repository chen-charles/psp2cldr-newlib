#ifndef _NO_EXECVE

/* execve.c */

/* This and the other exec*.c files in this directory require 
   the target to provide the _execve syscall.  */


#include <unistd.h>

#if 0

int
execve (const char *path,
      char * const argv[],
      char * const envp[])
{
  return _execve (path, argv, envp);
}

#endif

#endif /* !_NO_EXECVE  */
