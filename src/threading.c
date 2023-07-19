#include "threading.h"

#ifdef LINUX
thread_handle_t create_thread(thread_function function)
{
    thread_handle_t handle = INVALID_THREADHANDLE;
    pthread_create(&handle, NULL, function, NULL);
    return handle;
}
#endif
