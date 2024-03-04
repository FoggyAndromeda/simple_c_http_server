#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
// avoid pulling too much stuff from transitive dependency on <windows.h>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <ws2tcpip.h>

typedef int socklen_t;
typedef int ssize_t;

// instead of specifying this library in project dependencies explicitly
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
// #include <unistd.h>

typedef int SOCKET;

#define closesocket(s) close(s)
#endif
