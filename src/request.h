#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct st_request
{
    char *resourse;
    unsigned int resourse_len;
} st_request;

st_request *generate_request(const char *request_text, int request_len);
void clean_request(st_request *request);