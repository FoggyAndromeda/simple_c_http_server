#pragma once
#include <string.h>
#include <stdlib.h>

typedef struct st_response
{
    int status;
    char *data;
    unsigned int data_len;
} st_response;

int response_to_char(const st_response *response, char *result);
void clean_response(st_response *response);
