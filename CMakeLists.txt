cmake_minimum_required(VERSION 3.5.0)
project(SGGL VERSION 0.0.0)

include_directories(./inc/ ./thrid-party/)

if(EXISTS ./test/)
    add_subdirectory(test)
endif()

if(EXISTS ./sample/)
    add_subdirectory(./sample/)
endif()