#pragma once

#include <pthread.h>

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

typedef void* threading_thread_return_type_t;
typedef pthread_t threading_thread_handle_t;
typedef pthread_mutex_t threading_critical_section_t;
typedef threading_thread_return_type_t (*threading_thread_function)(void* puser_data);

threading_thread_handle_t threading_create_thread(threading_thread_function function);
void threading_join_thread(threading_thread_handle_t handle);
void threading_initialize_critical_section(threading_critical_section_t* pcritical_section);
void threading_lock_critical_section(threading_critical_section_t* pcritical_section);
void threading_unlock_critical_section(threading_critical_section_t* pcritical_section);
