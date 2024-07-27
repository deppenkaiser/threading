#include "threading/threading.h"

#include <errno.h>

void threading_sleep(enum threading_time_resolution mode, uint32_t duration)
{
    struct timespec ts = {0};

    switch (mode)
    {
        case TTR_NANO:
            ts.tv_nsec = duration;
            break;
    
        case TTR_MICRO:
            ts.tv_nsec = 1000 * duration;
            break;
    
        case TTR_MILLI:
            ts.tv_nsec = 1000 * 1000 * duration;
            break;
    
        case TTR_SECOND:
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

void threading_initialize_semaphore(threading_semaphore_t semaphore, uint32_t value)
{
    sem_init(semaphore, 0, value);
}

void threading_destroy_semaphore(threading_semaphore_t semaphore)
{
    sem_destroy(semaphore);
}

void threading_increment_semaphore(threading_semaphore_t semaphore)
{
    sem_post(semaphore);
}

bool threading_wait_semaphore(threading_semaphore_t semaphore, enum threading_time_resolution mode, uint32_t duration)
{
    bool no_timeout = false;
    struct timespec ts = {0};

    clock_gettime(CLOCK_REALTIME, &ts);

    switch (mode)
    {
        case TTR_NANO:
            ts.tv_nsec += duration;
            break;
    
        case TTR_MICRO:
            ts.tv_nsec += 1000 * duration;
            break;
    
        case TTR_MILLI:
            ts.tv_nsec += 1000 * 1000 * duration;
            break;
    
        case TTR_SECOND:
            ts.tv_sec += duration;
            break;
    }

    int32_t ret_value = sem_timedwait(semaphore, &ts);
    return (ret_value != ETIMEDOUT) && (ret_value != -1);
}
