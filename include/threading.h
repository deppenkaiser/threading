#pragma once

#ifdef LINUX
#include <pthread.h>

typedef pthread_t thread_handle_t;
typedef void* thread_return_type_t;

#define INVALID_THREADHANDLE (pthread_t) NULL

#endif

typedef thread_return_type_t (*thread_function)(void* puser_data);

thread_handle_t create_thread(thread_function function);
