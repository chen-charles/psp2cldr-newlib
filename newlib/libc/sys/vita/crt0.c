extern void exit(int);
int _init_signal(void);
int main(int argc, const char *argv[]);

/* The maximum number of arguments that can be passed to main(). */
#define ARGC_MAX 19

/* 
 * Code below is based on the PSPSDK implementation  
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org> 
 */
void _start(unsigned int args, void *argp)
{
    if (_init_signal() != 0)
    {
        exit(0x12345678);
    }

    char *argv[ARGC_MAX + 1] = {""}; // Program name
    int argc = 1;
    int loc = 0;
    char *ptr = argp;

    /* Turn our thread arguments into main()'s argc and argv[]. */
    while (loc < args)
    {
        argv[argc] = &ptr[loc];
        loc += strnlen(&ptr[loc], args - loc) + 1;
        argc++;
        if (argc == ARGC_MAX)
        {
            break;
        }
    }

    argv[argc] = 0;
    exit(main(argc, argv));
}
