#pragma once

#ifdef LINUX
#include <pthread.h>

typedef void* threading_thread_return_type_t;
typedef pthread_t threading_thread_handle_t;
typedef pthread_mutex_t threading_critical_section_t;

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

#endif // LINUX

#ifdef WINDOWS

#include <stdbool.h>
#include <windows.h>

typedef DWORD threading_thread_return_type_t;
typedef HANDLE threading_thread_handle_t;
typedef CRITICAL_SECTION threading_critical_section_t;

#define THREADING_INVALID_THREADHANDLE NULL

#endif

typedef threading_thread_return_type_t (*threading_thread_function)(void* puser_data);

threading_thread_handle_t threading_create_thread(threading_thread_function function);
void threading_join_thread(threading_thread_handle_t handle);
void threading_initialize_critical_section(threading_critical_section_t* pcritical_section);
void threading_lock_critical_section(threading_critical_section_t* pcritical_section);
void threading_unlock_critical_section(threading_critical_section_t* pcritical_section);
