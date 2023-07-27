#include "lserver.h"

int set_max_clients(server_t *server, size_t maxClients)
{
    if (maxClients <= 0)
        return (-1);
    
    server->maxClients = maxClients;
    return (0);
}

int set_max_pending(server_t *server, size_t maxPending)
{
    if (maxPending <= 0)
        return (-1);
    
    server->maxPending = maxPending;
    return (0);
}

int set_packet_max_size(server_t *server, size_t packetMaxSize)
{
    if (packetMaxSize <= 0)
        return (-1);
    server->packetMaxSize = packetMaxSize;
    return (0);
}

int set_crlf(server_t *server, char *message)
{
    if (message == NULL || strlen(message) == 0)
        return (-1);
    
    server->crlf = message;
    return (0);
}