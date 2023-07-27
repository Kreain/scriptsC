#include "lserver.h"

static packet_t generate_packet(server_t* server, char* message)
{
    if (strlen(message) <= 0)
        return ((packet_t) { NULL, 0 });

    char* crlf = server->crlf;
    size_t msgLen = strlen(message);
    size_t crlfLen = strlen(crlf);
    size_t dataSize = msgLen + crlfLen;

    char* data = malloc(dataSize + 1);
    if (data == NULL)
        return ((packet_t) { NULL, 0 });
        
    for (size_t i = 0; i < msgLen; i++)
        data[i] = message[i];
    for (size_t i = 0; i < crlfLen; i++)
        data[msgLen + i] = crlf[i];

    data[dataSize] = '\0';

    return ((packet_t) { data, dataSize });
}

int send_response(server_t *server, server_client_t client, char* message)
{
    if (strlen(message) <= 0)
        return (-1);

    packet_t packet = generate_packet(server, message);
    if (write(client.socket, packet.data, packet.size) < 0)
        return (-2);
    printf("Send message to %i\n", client.socket);
    return (0);
}

int broadcast_message(server_t* server, char* message)
{
    if (strlen(message) <= 0)
        return (-1);

    printf("sending\n");
    packet_t packet = generate_packet(server, message);
    for (size_t i = 0; i < server->maxClients; i++) {
        printf("server max clients: %li\n", server->maxClients);
        server_client_t client = server->clients[i];
        printf("broadcasting to client: %i\n", client.socket);
        if (client.socket >= 0 && write(client.socket, packet.data, packet.size) < 0)
            return (-2);
    }
    return (0);
}

int broadcast_others(server_t* server, server_client_t client, char* message)
{
    if (message == NULL || strlen(message) == 0)
        return (-1);

    packet_t packet = generate_packet(server, message);
    for (size_t i = 0; i < server->maxClients; i++) {
        server_client_t tmpClient = server->clients[i];
        if (i != client.index && tmpClient.socket >= 0 && write(tmpClient.socket, packet.data, packet.size) < 0)
            return (-2);
    }
    return (0);
}