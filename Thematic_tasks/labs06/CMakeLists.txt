cmake_minimum_required(VERSION 2.8.9)
project(labs06)
set(CMAKE_CXX_STANDARD 11)
set(NAME labs06)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${NAME} ${SOURCES})
