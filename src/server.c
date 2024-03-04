#include "server.h"

void server_main(const char *address, const char *port)
{
    struct sockaddr_in server_address;
    SOCKET sock;

#ifdef _WIN32
    WSADATA WsaData;
    WSAStartup(MAKEWORK(2, 2), &wsaData);
#endif

    memset(&server_address, 0, sizeof(server_address));

#ifdef __BSD_VISIBLE
    sin.sin_len = sizeof(server_address);
#endif

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));

    switch (inet_pton(AF_INET, address, &server_address.sin_addr))
    {
    case -1:
        fprintf(stderr, "inet_pton\n");
        exit(1);
    case 0:
        fprintf(stderr, "invalid host");
        exit(1);
    }

    printf("Starting tcp server at %s:%u\n", address, ntohs(server_address.sin_port));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "problems with sock creation\n");
        exit(1);
    }

    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        fprintf(stderr, "problems with sock binding\n");
        exit(1);
    }

    if (listen(sock, 10))
    {
        fprintf(stderr, "problems with listening\n");
        exit(1);
    }

    char buffer_request[BUFFER_SIZE];
    char buffer_response[BUFFER_SIZE];

    for (int client_socket, len;
         (client_socket = accept(sock, (struct sockaddr *)&server_address, &len)) != -1;
         len = sizeof(server_address))
    {
        ssize_t bytes_read;
        bytes_read = recv(client_socket, buffer_request, BUFFER_SIZE - 1, 0);

        st_request *request = generate_request(buffer_request, bytes_read);
        st_response *response = generate_response_for_request(request);

        int response_len = response_to_char(response, buffer_response);
        printf("Response: %s\n", buffer_response);

        send(client_socket, buffer_response, strlen(buffer_response), 0);

        closesocket(client_socket);
    }
    closesocket(sock);

#ifdef _WIN32
    WSACleanup();
#endif
}

st_response *generate_response_for_request(st_request *request)
{
    // TODO: some logic with request, mock for now
    st_response *result = malloc(sizeof(st_response));
    result->data = (char *)malloc(BUFFER_SIZE);
    strcpy(result->data, "<h1>hello</h1>\r\n");
    result->data_len = strlen(result->data);
    result->status = 200;

    return result;
}
