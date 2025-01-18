cmake_minimum_required(VERSION 3.16)

project(MainProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wpedantic -Wextra -Werror -pedantic-errors)

set(SOURCES
    src/main.cpp
    src/01-convert-hex-to-base64.cpp
)

add_executable(main ${SOURCES})
