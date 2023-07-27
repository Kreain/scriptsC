#include "lserver.h"
#include <stdio.h>

server_t *create_server(char *hostname, uint16_t port, protocol_t protocol)
{

    server_t *server;

    if (hostname == NULL || strlen(hostname) == 0) {
        return throw_exception(NULL, EXCEPTION_NULL_HOSTNAME);
    }
    if ((server = malloc(sizeof(server_t))) == NULL)
        return (NULL);

    server->port = port;
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(port);
    server->maxClients = DEFAULT_MAX_CLIENTS;
    server->maxPending = DEFAULT_PENDING_CLIENTS;
    server->packetMaxSize = DEFAULT_PACKET_MAX_SIZE;
    server->protocol = protocol;
    server->active = false;
    server->clients = NULL;
    server->lastActivity.type = NOTHING;
    server->lastActivity.message = NULL;
    server->crlf = DEFAULT_CRLF;

    return (server);
}

int start_server(server_t *server)
{
    if (init_server(server) < 0 || init_options(server) < 0 ||
        bind_server(server) < 0 || listen_server(server) < 0)
        return (-1);

    server->active = true;
    if ((server->clients = malloc(sizeof(server_client_t) * server->maxClients)) == NULL)
        return (-2);
    for (size_t i = 0; i < server->maxClients; i++)
    {
        server->clients[i].socket = -2;
        server->clients[i].index = i;
    }
    return (0);
}

void stop_server(server_t *server)
{
    if (!server->active)
        return;

    for (size_t i = 0; i < server->maxClients; i++)
    {
        server_client_t client = server->clients[i];
        if (client.socket >= 0)
            close(client.socket);
    }
    close(server->socket);
    free(server->clients);
    if (server->lastActivity.message != NULL)
        free(server->lastActivity.message);
    server->active = false;
}

void destroy_server(server_t *server)
{
    if (server->active)
        stop_server(server);
    if (server != NULL)
        free(server);
}
