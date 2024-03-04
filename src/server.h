#pragma once

#include "common.h"
#include "request.h"
#include "response.h"

#define BUFFER_SIZE 1024

void server_main(const char *address, const char *port);
static st_response *generate_response_for_request(st_request *request);
