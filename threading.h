#pragma once

#include <pthread.h>
#include <unistd.h>

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

typedef pthread_mutex_t threading_critical_section;
typedef threading_critical_section* threading_critical_section_t;
typedef void* (*threading_thread_function)(void* puser_data);

pthread_t threading_create_thread(threading_thread_function function, void* data);
void threading_join_thread(pthread_t handle);
void threading_initialize_critical_section(threading_critical_section_t critical_section);
void threading_destroy_critical_section(threading_critical_section_t critical_section);
void threading_lock_critical_section(threading_critical_section_t critical_section);
void threading_unlock_critical_section(threading_critical_section_t critical_section);
