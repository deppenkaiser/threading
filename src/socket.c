#include "threading.h"

socket_handle_t socket_create_socket()
{
    socket_handle_t receive = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval tv_connect = {0};

    tv_connect.tv_sec = 5;
    tv_connect.tv_usec = 0;

    if (receive != -1)
    {
        if (setsockopt(receive, SOL_SOCKET, SO_RCVTIMEO, &tv_connect, sizeof(tv_connect)) == -1)
        {
            socket_close(&receive);
        }
    }

    return receive;
}

bool socket_bind_and_listen(socket_handle_t socket)
{
    bool bRetVal = false;
    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5000);

    if (bind(socket, (struct sockaddr*) &server, sizeof(server)) != -1)
    {
        if (listen(socket, 1) != -1)
        {
            bRetVal = true;
        }
    }

    return bRetVal;
}

socket_handle_t socket_accept_incomming_connection(socket_handle_t socket)
{
    bool bRetVal = false;
    struct sockaddr_in clientAddr = {0};
    socklen_t nSizeBytes = sizeof(clientAddr);
    socket_handle_t client = accept(socket, (struct sockaddr*) &clientAddr, &nSizeBytes);
    struct timeval tv = {0};

    tv.tv_sec = 0;
    tv.tv_usec = 100 * 1000;

    if (setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
    {
        close(client);
        client = SOCKET_INVALID_SOCKET;
    }

    return client;
}

void socket_close(socket_handle_t* psocket)
{
    close(*psocket);
    *psocket = SOCKET_INVALID_SOCKET;
}
