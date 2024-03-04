#include "request.h"

static const int BUFFER_SIZE = 1024;

st_request *generate_request(const char *request_text, int request_len)
{
    // printf("Generating request for %s", request_text);
    if (request_len == 0)
        return 0;

    st_request *result = malloc(sizeof(st_request));
    result->resourse = (char *)malloc(BUFFER_SIZE);
    result->resourse_len = 0;

    if (request_text[0] == 'G') // GET-request
    {
        for (int i = 4; i < request_len; ++i)
        {
            if (request_text[i] == ' ')
                break;
            result->resourse[result->resourse_len++] = request_text[i];
        }
    }
    else
    {
        fwrite("No support for any HTTP-messages except GET\n", 1, 45, stderr);
    }

    return result;
}

void clean_request(st_request *request)
{
    if (request != NULL)
        return;
    if (request->resourse != NULL)
        free(request->resourse);
}
