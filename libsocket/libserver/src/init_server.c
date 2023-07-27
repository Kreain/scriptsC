#include "lserver.h"

int init_server(server_t *server)
{
    if ((server->socket = socket(server->address.sin_family,
                             (server->protocol == TCP) ? SOCK_STREAM : SOCK_DGRAM,
                             getprotobyname((server->protocol == TCP ? "TCP" : "UDP"))->p_proto)) < 0)
        return (-1);
    return (0);
}

int init_options(server_t *server)
{
    int opt = 1;
    
    #ifdef __unix__
        if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
            return (-1);
    #else
        if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
            return (-1);
    #endif

    return (0);
}

int bind_server(server_t *server)
{
    if (bind(server->socket, (struct sockaddr *)&(server->address), sizeof(server->address)) < 0)
        return (-1);
    return (0);
}

int listen_server(server_t *server)
{
    if (listen(server->socket, 5) < 0)
        return (-1);
    return (0);
}