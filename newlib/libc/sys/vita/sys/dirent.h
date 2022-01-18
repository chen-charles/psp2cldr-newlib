#include <sys/types.h>
#include <sys/lock.h>

#ifdef __cplusplus
extern "C" {
#endif

struct __lock
{
    int _opaque;
};

typedef struct
{
    int dd_fd;		/* directory file */
    int dd_loc;		/* position in buffer */
    int dd_seek;
    char *dd_buf;	/* buffer */
    int dd_len;		/* buffer length */
    int dd_size;	/* amount of data in buffer */
    _LOCK_RECURSIVE_T dd_lock;
} DIR;

struct dirent
{
    ino_t d_ino;
    off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
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
