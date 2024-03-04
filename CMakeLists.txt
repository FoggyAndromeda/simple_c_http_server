cmake_minimum_required(VERSION 3.14)

project(chttpserver)

set(
    SRC_FILES

    src/main.c
    src/server.c
    src/response.c
    src/request.c
)

set(
    HEADER_FILES

    src/common.h
    src/server.h
    src/response.h
    src/request.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
