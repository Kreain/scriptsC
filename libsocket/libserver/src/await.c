#include "lserver.h"

static int find_empty_space(server_t *server)
{
    for (size_t index = 0; index < server->maxClients; index++)
        if (server->clients[index].socket == -2)
            return (index);
    return (-1);
}

int await_activity(server_t *server)
{
    fd_set readfds;
    int max_sd = 0;
    activity_t activity;

    if (!server || !server->active)
        return (-42);
    if (server->lastActivity.type == DISCONNECTION)
    {
        int index = server->lastActivity.client.index;
        if (server->clients[index].socket >= 0)
            close(server->clients[index].socket);
        server->clients[index].socket = -2;
    }
    if (server->lastActivity.message != NULL)
        free(server->lastActivity.message);

    server->addrlen = sizeof(server->address);
    FD_ZERO(&readfds);
    FD_SET(server->socket, &readfds);
    max_sd = server->socket;

    for (size_t i = 0; i < server->maxClients; i++)
    {
        server_client_t client;
        client = server->clients[i];

        if (client.socket > 0)
            FD_SET(client.socket, &readfds);
        if (client.socket > max_sd)
            max_sd = client.socket;
    }

    if (select(max_sd + 1, &readfds, NULL, NULL, NULL) < 0)
        return (-1);

    if (FD_ISSET(server->socket, &readfds))
    {
        int index;
        server_client_t client;

        if ((index = find_empty_space(server)) < 0)
            return (-2);

        client = server->clients[index];
        if ((client.socket = accept(server->socket, (struct sockaddr *)&(server->address), (socklen_t *)&(server->addrlen))) < 0)
            return (-1);
        client.address = server->address;
        client.addrlen = sizeof(client.address);
        server->clients[index] = client;
        activity = (activity_t){CONNECTION, client, NULL};
    }
    else
    {
        for (size_t i = 0; i < server->maxClients; i++)
        {
            size_t valread;
            server_client_t client = server->clients[i];
            if (client.socket != -2 && FD_ISSET(client.socket, &readfds))
            {
                activity.message = malloc(server->packetMaxSize + 1);
                valread = read(client.socket, activity.message, server->packetMaxSize);
                if (valread == 0)
                {
                    free(activity.message);
                    activity = (activity_t){DISCONNECTION, client, NULL};
                }
                else
                {
                    activity.message[valread] = '\0';
                    if (activity.message[valread - 1] == '\n')
                        activity.message[valread - 1] = '\0';
                    activity.type = MESSAGE;
                    activity.client = client;
                    printf("message: %s\n", activity.message);
                }
            }
        }
    }
    server->lastActivity = activity;
    return (0);
}