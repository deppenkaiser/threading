#include "threading/threading.h"

threading_thread_handle_t threading_create_thread(threading_thread_function function)
{
    threading_thread_handle_t handle = THREADING_INVALID_THREADHANDLE;
    pthread_create(&handle, NULL, function, NULL);
    return handle;
}

void threading_join_thread(threading_thread_handle_t handle)
{
    pthread_join(handle, NULL);
}

void threading_initialize_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_init(pcritical_section, NULL);
}

void threading_lock_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_lock(pcritical_section);
}

void threading_unlock_critical_section(threading_critical_section_t* pcritical_section)
{
    pthread_mutex_unlock(pcritical_section);
}
