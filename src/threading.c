#include "threading/threading.h"

pthread_t threading_create_thread(threading_thread_function function)
{
    pthread_t handle = THREADING_INVALID_THREADHANDLE;
    pthread_create(&handle, NULL, function, NULL);
    return handle;
}

void threading_join_thread(pthread_t handle)
{
    pthread_join(handle, NULL);
}

void threading_initialize_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutexattr_t mutexattr = {0};
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(pcritical_section, &mutexattr);
}

void threading_destroy_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_destroy(pcritical_section);
}

void threading_lock_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_lock(pcritical_section);
}

void threading_unlock_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_unlock(pcritical_section);
}
