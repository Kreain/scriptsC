#include "lclient.h"
#include <stdio.h>
#include <errno.h>

int connect_client(client_t* client)
{
    if (connect(client->socket, (struct sockaddr*)&(client->address), sizeof(client->address)) < 0)
        return (-1);
    client->connected = true;
    return (0);
}

bool client_is_connected(client_t* client) {
    return (client->connected);
}

client_t* create_client(char* hostname, uint16_t port)
{
    client_t* client = malloc(sizeof(client_t));

    if (!client)
        return (NULL);

    if ((client->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        free(client);
        return (NULL);
    }

    client->address.sin_family = AF_INET;
    client->address.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &(client->address.sin_addr)) <= 0) {
        free(client);
        return (NULL);
    }
    client->connected = false;
    client->readReady = false;

    return (client);
}

int send_message(client_t* client, char* message)
{
    if (message == NULL || strlen(message) == 0)
        return (-1);

    if (write(client->socket, message, strlen(message)) < 0)
        return (-2);
    return (0);
}

int update_client(client_t* client)
{
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(client->socket, &readfds);

    if (select(client->socket + 1, &readfds, NULL, NULL, NULL) < 0)
        perror("");

    if (FD_ISSET(client->socket, &readfds)) {
        char buffer[30];
        int valread;
        int total = 0;
        char* str = NULL;

        printf("loop\n");
        while ((valread = read(client->socket, buffer, sizeof(buffer) - 1)) > 0) {
            buffer[valread] = 0;
            str = (char*)realloc(str, total + valread);
            for (int i = 0; i < valread; i++)
                str[total + i] = buffer[i];
            total += valread;
            if (valread < 29 && buffer[valread - 2] == '\r' && buffer[valread - 1] == '\n') {
                printf("herllo\n");
                break;
            }
            memset(buffer, 0, sizeof(buffer));
        }
        str = realloc(str, total + 1);
        str[total] = '\0';
        printf("done\n");
        printf("str: %s\n", str);
        if (valread < 0)
            perror("");
        if (total == 0)
            exit(0);
        // valread = read(client->socket, socket_buffer, 1024);
        // if (valread < 0)
        //     perror("");
        // else {
        //     socket_buffer[valread] = '\0';
        //     printf("Received message: %s\n", socket_buffer);
        // }
    }
    return (0);
}