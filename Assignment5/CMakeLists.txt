cmake_minimum_required(VERSION 3.26)
project(Assignment5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment5 movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_movie.h movieTheaterDB.h)
add_executable(main movieTheaterDB_movie.c)