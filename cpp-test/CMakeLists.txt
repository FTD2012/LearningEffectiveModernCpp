cmake_minimum_required(VERSION 3.7)
project(cpp_test)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}-fno-elide-constructors")
message(STATUS "optional:-std=c++14")

include_directories(.)

if(3-3-3)
    add_subdirectory(3-3-3)
endif(3-3-3)

if(3-3-4)
    add_subdirectory(3-3-4)
endif(3-3-4)

if(3-3-6)
    add_subdirectory(3-3-6)
endif(3-3-6)

if(3-3-7)
    add_subdirectory(3-3-7)
endif(3-3-7)

if(3-3-9)
    add_subdirectory(3-3-9)
endif(3-3-9)

if(decltype)
    add_subdirectory(decltype)
endif(decltype)

ADD_SUBDIRECTORY(3-3-3)
ADD_SUBDIRECTORY(3-3-4)
ADD_SUBDIRECTORY(3-3-6)
ADD_SUBDIRECTORY(3-3-7)
ADD_SUBDIRECTORY(3-3-9)
ADD_SUBDIRECTORY(decltype)

#add_executable(cpp_test ${SOURCE_FILES})