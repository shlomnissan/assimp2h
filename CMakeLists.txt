cmake_minimum_required(VERSION 3.22.1)

project(assimp2h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt REQUIRED)
find_package(assimp REQUIRED)
find_package(gflags REQUIRED)

set(SOURCES
    src/main.cpp
    src/reader.cpp
    src/reader.h
    src/writer.cpp
    src/writer.h
)

add_executable(assimp2h ${SOURCES})

target_link_libraries(assimp2h PRIVATE fmt::fmt assimp::assimp gflags::gflags)