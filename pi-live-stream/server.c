/**
 * @file server.c
 * @brief 
 *
 *
*/

#include <errno.h>

#include "server.h"

int start_http_server(int port)
{
    struct sockaddr_in addr;        // Internet IPv4 socket address
    char buffer[BUFFER_SIZE];

    /**
     * 1. Create an IPv4 TCP socket
     *  - Socket() arguments:
     *     1. domain: AF_INET (protocol family) -> IPv4 Internet protocol
     *     2. socket type: SOCK_STREAM -> connection-oriented stream (TCP)
     *     3. protocol = 0; -> exact protocol inside selected domain + type.
    */
    sctx->server_fd = socket(AF_NET, SOCK_STREAM, 0);
    if (sctx->server_fd < 0) {
        perror("server: socket");
        return -1;
    }

    // Prepare server address structure 
    memset(&addr, 0, sizeof(addr));
    addr.sin_family      = AF_INET;             // IPv4
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   // Listen on all interface
    addr.sin_port        = htons(port);         // Convert port to network byte order

    // 2. Bind the socket to the chosen address & port
    if (bind(sctx->server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("server: bind");
        close(sctx->server_fd);
        return -1;
    }

    // Mark socket as listening (Ready to accept clients)
    if (listen(sctx->server_fd, 4) < 0) {
        perror("server: listen");
        close(sctx->server_fd);
        return -1;
    }

    return 0;
}

int accept_client_connection(struct stream_ctx *sctx) 
{
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);

    // Block until a client connects
    sctx->client_fd = accept(sctx->server_fd, (struct sockaddr*)&client_addr, &addrlen);
    if (sctx->client_fd < 0) {
        perror("server: accept"); 
        close(sctx->server_fd);
        return -1;
    }
}

int process_http_request(struct stream_ctx *sctx) 
{
    char start_stream = "/start-stream";
    char stop_stream = "/stop-stream";

    // Read the HTTP request
    memset(buffer, 0, BUFFER_SIZE);
    read(sctx->client_fd, buffer, BUFFER_SIZE -1);

    // Start/Stop stream if correct Request command received `/stop-stream` or `/start-stream`
    if (strcmp(start_stream, buffer, strlen(start_stream))) 
    {
        // Start the stream
        // We are running the FFmpeg command here
    }
    else if (strcmp(start_stream, buffer, strlen(start_stream)))
    {
        // Stop the stream
        
    } else {
        printf("server: HTTP request recieved is unknown\n");
        return -1
    }
    return 0;
}

