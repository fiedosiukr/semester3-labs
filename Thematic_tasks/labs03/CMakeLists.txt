cmake_minimum_required(VERSION 2.8.9)
project(labs03)

set(NAME labs03)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${NAME} ${SOURCES})