cmake_minimum_required(VERSION 3.5)

project(Boardgames LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FILE(GLOB SRCs src/*.cpp)
FILE(GLOB INCLDUES include/*.h)

include_directories(include/)

add_executable(Boardgames main.cpp ${SRCs} ${INCLUDES})
