#pragma once

#ifdef LINUX
#include <pthread.h>

typedef pthread_t threading_thread_handle_t;
typedef pthread_mutex_t threading_critical_section_t;
typedef void* threading_thread_return_type_t;

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

/************************************ socket ******************************************/

#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

typedef int socket_handle_t;

#define SOCKET_INVALID_SOCKET -1

#endif // LINUX

typedef threading_thread_return_type_t (*threading_thread_function)(void* puser_data);

threading_thread_handle_t threading_create_thread(threading_thread_function function);
void threading_join_thread(threading_thread_handle_t handle);
void threading_initialize_critical_section(threading_critical_section_t* pcritical_section);

/************************************ socket ******************************************/

socket_handle_t socket_create_socket();
bool socket_bind_and_listen(socket_handle_t socket);
socket_handle_t socket_accept_incomming_connection(socket_handle_t socket);
void socket_close(socket_handle_t* psocket);
