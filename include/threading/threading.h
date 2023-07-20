#pragma once

#ifdef LINUX
#include <pthread.h>

typedef void* threading_thread_return_type_t;
typedef pthread_t threading_thread_handle_t;
typedef pthread_mutex_t threading_critical_section_t;

#define THREADING_INVALID_THREADHANDLE (pthread_t) NULL

/************************************ socket ******************************************/

#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

typedef int socket_handle_t;

#define SOCKET_INVALID_SOCKET -1
#define SOCKET_ERROR -1

#endif // LINUX

#ifdef WINDOWS

#include <WinSock2.h>
#include <stdbool.h>
#include <windows.h>

typedef DWORD threading_thread_return_type_t;
typedef HANDLE threading_thread_handle_t;
typedef CRITICAL_SECTION threading_critical_section_t;

#define THREADING_INVALID_THREADHANDLE NULL

/************************************ socket ******************************************/

typedef SOCKET socket_handle_t;

#endif

typedef threading_thread_return_type_t (*threading_thread_function)(void* puser_data);

threading_thread_handle_t threading_create_thread(threading_thread_function function);
void threading_join_thread(threading_thread_handle_t handle);
void threading_initialize_critical_section(threading_critical_section_t* pcritical_section);
void threading_lock_critical_section(threading_critical_section_t* pcritical_section);
void threading_unlock_critical_section(threading_critical_section_t* pcritical_section);

/************************************ socket ******************************************/

socket_handle_t socket_create_socket();
bool socket_bind_and_listen(socket_handle_t socket);
socket_handle_t socket_accept_incomming_connection(socket_handle_t socket);
void socket_close(socket_handle_t* psocket);

/************************************ string ******************************************/

