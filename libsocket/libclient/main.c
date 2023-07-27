#include "lclient.h"
#include <stdio.h>

int main(void)
{

    client_t* client = create_client("127.0.0.1", 3636);

    if (connect_client(client) < 0)
        return (-1);

    while (client_is_connected(client)) {
        update_client(client);
    }

    return (0);
}