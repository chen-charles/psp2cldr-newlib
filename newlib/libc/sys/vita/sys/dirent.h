#include <sys/types.h>
#include <sys/lock.h>

#ifdef __cplusplus
extern "C" {
#endif

struct __lock
{
    int _handle;
};

typedef struct
{
    int _handle;
} DIR;

struct dirent
{
    ino_t d_ino;
    char d_name[256];
};

int            closedir(DIR *);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *, struct dirent *, struct dirent **);
void           rewinddir(DIR *);
void           seekdir(DIR *, long int);
long int       telldir(DIR *);

#ifdef __cplusplus
}
#endif
