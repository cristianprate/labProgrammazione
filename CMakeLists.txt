cmake_minimum_required(VERSION 3.25)
project(labProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Subject.h Observer.h Note.cpp Note.h Collection.cpp Collection.h Application.cpp Application.h BlockedObserver.cpp BlockedObserver.h)
add_executable(labProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(labProgrammazione core)