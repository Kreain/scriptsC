#ifndef LSERVER_CLIENT_H_
#define LSERVER_CLIENT_H_

typedef struct protoent protoent_t;
typedef struct sockaddr_in sockaddr_in_t;

typedef struct server_client_s {
    int socket;
    sockaddr_in_t address;
    int addrlen;
    size_t index;
} server_client_t;

#endif