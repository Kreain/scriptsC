#include "lserver.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{

    server_t *server = create_server("", 3636, TCP);

    if (server == NULL) {
        show_server_exception();
        return (84);
    }

    int start = start_server(server);

    if (start < 0) {
        printf("start returned: %i\n", start);
        perror("");
        exit(start);
    }

    if (server->active)
        printf("Server started on: %s:%d\n", inet_ntoa(server->address.sin_addr), ntohs(server->address.sin_port));

    while (server != NULL && server->active)
    {
        activity_t activity;
        server_client_t client;

        int act;

        if ((act = await_activity(server)) < 0)
        {
            printf("an error occured: %i\n", act);
            perror("");
            exit(0);
        }

        activity = server->lastActivity;
        client = server->lastActivity.client;
        switch (activity.type)
        {
        case CONNECTION:
        {
            printf("[%s:%d](%li) has joined the server\n", inet_ntoa(client.address.sin_addr), ntohs(client.address.sin_port),
                   client.index);
            send_response(server, client, "Welcome to the Server. Please read the guidelines before you start anything.");
            broadcast_others(server, client, "A user has joined the server, welcome him nicely. OR DIE.");
        }
        break;
        case MESSAGE:
        {
            printf("[%s:%d](%li) says '%s'\n", inet_ntoa(client.address.sin_addr), ntohs(client.address.sin_port),
                   client.index, activity.message);
            broadcast_message(server, activity.message);
            if (strcmp(activity.message, "STOP") == 0)
                stop_server(server);
        }
        break;
        case DISCONNECTION:
        {
            printf("[%s:%d](%li) disconnected\n", inet_ntoa(client.address.sin_addr), ntohs(client.address.sin_port),
                   client.index);
            broadcast_others(server, client, "A user has disconnected, don't let him get away...");
        }
        break;
        default:
            break;
        }
    }

    destroy_server(server);

    return (0);
}