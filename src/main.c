#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

int main(int argc, char **argv)
{
    if (argc == 3)
        server_main(argv[1], argv[2]);
    else
        server_main("127.0.0.1", "80");

    return 0;
}
