cmake_minimum_required(VERSION 3.17)
project(template_alumnos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(template_alumnos
        lib/googletest-master.zip
        cases.cpp
        cases.h
        ejercicios.cpp
        ejercicios.h
        main.cpp)
