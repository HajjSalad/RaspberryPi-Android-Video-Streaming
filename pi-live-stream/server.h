#ifndef SERVER_H
#define SERVER_H

/**
 * @file server.h
 * @brief 
*/

#define SERVER_PORT     8000

/**
* @brief Streaming context for HTTP server.
*
* Holds the server socket and client socket
*/
struct stream_ctx {
    int server_fd;
    int client_fd;
};

// Function Prototype
int server_start(int port);

#endif