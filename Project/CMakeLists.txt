cmake_minimum_required(VERSION 2.8.9)
project(cmake-test)

set(NAME remember-me)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${NAME} ${SOURCES})

target_link_libraries(${NAME} PUBLIC allegro
                    allegro_primitives)

