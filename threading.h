#pragma once

#include <pthread.h>
#include <unistd.h>
#include <stdint.h>
#include <semaphore.h>

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

typedef pthread_mutex_t threading_critical_section;
typedef threading_critical_section* threading_critical_section_t;
typedef sem_t threading_semaphore;
typedef threading_semaphore* threading_semaphore_t;
typedef void* (*threading_thread_function)(void* user_data);

enum threading_sleep_resolution
{
    TSR_NANO,
    TSR_MICRO,
    TSR_MILLI,
    TSR_SECOND
};

pthread_t threading_create_thread(threading_thread_function function, void* user_data);
void threading_join_thread(pthread_t handle);
void threading_initialize_critical_section(threading_critical_section_t critical_section);
void threading_destroy_critical_section(threading_critical_section_t critical_section);
void threading_lock_critical_section(threading_critical_section_t critical_section);
void threading_unlock_critical_section(threading_critical_section_t critical_section);
void threading_initialize_semaphore(threading_semaphore_t semaphore, uint32_t value);
void threading_sleep(enum threading_sleep_resolution mode, uint32_t duration);
