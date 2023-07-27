#include "lserver.h"

server_exception_t server_exception = NO_EXCEPTIONS;

void *throw_exception(void *return_value, server_exception_t exception_type) {
    server_exception = exception_type;
    return (return_value);
}

void show_server_exception(void) {
    fprintf(stderr, "[lsocket-server-exception]: %s\n", EXCEPTION_MESSAGES[server_exception]);
}

const char *EXCEPTION_MESSAGES[] = {
    "No exceptions have been made",
    "Hostname cannot be null or empty",
    "Test"
};