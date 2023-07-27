/**
 * @file lserver.h
 * @author Kreain (martin.laplanche@epitech.eu)
 * @brief Main header file used for the libserver
 * @version 1.0
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LSERVER_H
#define LSERVER_H

#include "includes.h"
#include "enums.h"
#include "lserverclient.h"
#include "exceptions.h"

#define DEFAULT_MAX_CLIENTS 5
#define DEFAULT_PENDING_CLIENTS 5
#define DEFAULT_PACKET_MAX_SIZE 1024
#define DEFAULT_CRLF "\r\n"

typedef struct activity_s
{
    activity_type_t type;
    server_client_t client;
    char* message;
} activity_t;

typedef struct server_s
{
    uint16_t port;
    int socket;
    sockaddr_in_t address;
    int addrlen;
    protocol_t protocol;
    size_t maxClients;
    size_t maxPending;
    bool active;
    server_client_t* clients;
    size_t packetMaxSize;
    activity_t lastActivity;
    char *crlf;
} server_t;

typedef struct packet_s {
    char *data;
    size_t size;
} packet_t;

server_t* create_server(char* hostname, uint16_t port, protocol_t protocol);

int init_server(server_t* server);
int init_options(server_t* server);
int bind_server(server_t* server);
int listen_server(server_t* server);

int set_max_clients(server_t* server, size_t maxClients);
int set_max_pending(server_t* server, size_t maxPending);
int set_packet_max_size(server_t* server, size_t packetMaxSize);
int set_crlf(server_t *server, char *crlf);

int start_server(server_t* server);
void stop_server(server_t* server);
void destroy_server(server_t* server);

int send_response(server_t *server, server_client_t client, char *message);
int broadcast_message(server_t *server, char *message);
int broadcast_others(server_t *server, server_client_t client, char *message);

/**
 * \brief Await an activity on the server
 *
 * \param[in] server The server to which await an activity
 *
 * \arg On success, returns 0, and the activity is set to server->lastActivity
 * \arg -1 - There was an error and errno has been set
 * \arg -2 - New connection failed do to max clients reached
 * \arg -42 - The server is NULL or inactive
 */
int await_activity(server_t* server);

#endif /* LSERVER_H */
