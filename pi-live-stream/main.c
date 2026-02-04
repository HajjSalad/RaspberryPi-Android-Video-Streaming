/**
 * @file main.c
 * @brief Entry Point of the program
 *
 *
*/

#include <stdio.h>
#include "server.h"

int main(void)
{
    printf("\n*** Program Start ***\n");

    if(start_http_server(SERVER_PORT) < 0) {
        printf("main: Failed to start http server\n");
        return -1;
    }
    printf("main: HTTP server listeing on port %d\n", SERVER_PORT);

    // Main Server loop
    while(1) 
    {
        printf("main: Waiting for a client...\n\n");

        // Accept a client connection
        if (accept_client_connection(&sctx) < 0) {
            printf("main: Failed to accept client\n");
            continue;       // Kep server alive
        }
        printf("main: client connected\n");

        // Process the HTTP request
        if (process_http_request(&sctx) < 0) {
            printf("main: Error processing the HTTP request\n");
            continue;       // Keep server alive
        }

        printf("main: Client disconnected\n\n");
        close(sctx.client_fd);
        sctx.client_fd = -1;
    }

    return 0;
}