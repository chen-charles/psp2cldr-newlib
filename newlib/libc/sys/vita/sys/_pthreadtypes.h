#ifndef _SYS__PTHREADTYPES_H_
#define _SYS__PTHREADTYPES_H_

/*
     * Generic handle type - intended to extend uniqueness beyond
     * that available with a simple pointer. It should scale for either
     * IA-32 or IA-64.
     */
typedef unsigned int pte_handle_t;

typedef pte_handle_t pthread_t;
typedef struct pthread_attr_t_ *pthread_attr_t;
typedef struct pthread_once_t_ pthread_once_t;
typedef struct pthread_key_t_ *pthread_key_t;
typedef struct pthread_mutex_t_ *pthread_mutex_t;
typedef struct pthread_mutexattr_t_ *pthread_mutexattr_t;
typedef struct pthread_cond_t_ *pthread_cond_t;
typedef struct pthread_condattr_t_ *pthread_condattr_t;
typedef struct pthread_rwlock_t_ *pthread_rwlock_t;
typedef struct pthread_rwlockattr_t_ *pthread_rwlockattr_t;
typedef struct pthread_spinlock_t_ *pthread_spinlock_t;
typedef struct pthread_barrier_t_ *pthread_barrier_t;
typedef struct pthread_barrierattr_t_ *pthread_barrierattr_t;

#endif /* ! _SYS__PTHREADTYPES_H_ */
