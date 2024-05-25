#include "threading/threading.h"

void threading_sleep(enum threading_sleep_resolution mode, uint32_t duration)
{
    struct timespec ts = {0};

    switch (mode)
    {
        case TSR_NANO:
            ts.tv_nsec = duration;
            break;
    
        case TSR_MICRO:
            ts.tv_nsec = 1000 * duration;
            break;
    
        case TSR_MILLI:
            ts.tv_nsec = 1000 * 1000 * duration;
            break;
    
        case TSR_SECOND:
            ts.tv_sec = duration;
            break;
    }

    nanosleep(&ts, NULL); 
}

pthread_t threading_create_thread(threading_thread_function function, void* user_data)
{
    pthread_t handle = THREADING_INVALID_THREADHANDLE;
    pthread_create(&handle, NULL, function, user_data);
    return handle;
}

void threading_join_thread(pthread_t handle)
{
    pthread_join(handle, NULL);
}

void threading_initialize_critical_section(threading_critical_section_t critical_section)
{
    pthread_mutexattr_t mutexattr = {0};
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(critical_section, &mutexattr);
}

void threading_destroy_critical_section(threading_critical_section_t critical_section)
{
    pthread_mutex_destroy(critical_section);
}

void threading_lock_critical_section(threading_critical_section_t critical_section)
{
    pthread_mutex_lock(critical_section);
}

void threading_unlock_critical_section(threading_critical_section_t critical_section)
{
    pthread_mutex_unlock(critical_section);
}
