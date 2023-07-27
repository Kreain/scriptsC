#ifndef LCLIENT_H_
#define LCLIENT_H_

#include "includes.h"

typedef struct sockaddr_in sockaddr_in_t;

typedef struct client_s {
    int socket;
    sockaddr_in_t address;
    int addrlen;
    bool connected;
    bool readReady;
} client_t;

client_t *create_client(char *hostname, uint16_t port);

int connect_client(client_t *client);
bool client_is_connected(client_t *client);

int send_message(client_t *client, char *message);

int update_client(client_t *client);

#endif /* LCLIENT_H_ */
