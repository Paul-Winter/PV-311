<<<<<<< HEAD
cmake_minimum_required(VERSION 3.5)

project(CRTP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CRTP main.cpp)

install(TARGETS CRTP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
=======
cmake_minimum_required(VERSION 3.5)

project(CRTP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CRTP main.cpp)

install(TARGETS CRTP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
>>>>>>> db19fb261b408b31cbcd2cf7c34d63a8f55f2d17
