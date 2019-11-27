cmake_minimum_required(VERSION 2.8.9)
project(labs05)

set(NAME labs05)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${NAME} ${SOURCES})