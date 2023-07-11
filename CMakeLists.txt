cmake_minimum_required(VERSION 3.25)
project(labProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(labProgrammazione main.cpp Subject.cpp Subject.h Observer.cpp Observer.h Note.cpp Note.h Collection.cpp Collection.h)
