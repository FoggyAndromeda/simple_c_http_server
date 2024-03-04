#include "response.h"

int response_to_char(const st_response *response, char *result)
{
    int pos = 0;
    strcpy(result, "HTTP/1.1 ");
    pos += 9;
    switch (response->status)
    {
    case 200:
        strcpy(result + pos, "200 OK\r\n\r\n");
        pos += 10;
        break;
    default:
        strcpy(result + pos, "404 NOT FOUND\r\n\r\n");
        pos += 17;
        break;
    }
    strcpy(result + pos, response->data);
    return strlen(result);
}

void clean_response(st_response *response)
{
    if (!response)
        return;
    if (response->data)
        free(response->data);
}
