cmake_minimum_required(VERSION 3.5)

project(CRTP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CRTP main.cpp)

install(TARGETS CRTP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
