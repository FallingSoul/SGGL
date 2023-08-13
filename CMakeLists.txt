cmake_minimum_required(VERSION 3.5.0)
project(SGGL VERSION 0.0.0)

include_directories(./inc/ ./thrid-party/)
file(GLOB_RECURSE SGGL_HEADERS ./inc/sggl/*.*)

message("\n---------------- SGGL Headers Begin ----------------")
foreach(X ${SGGL_HEADERS})
    message("${X}")
endforeach()
message("----------------  SGGL Headers End  ----------------\n")


if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
    message("\n----------------test begin----------------")
    add_subdirectory(test)
    message("---------------- test end ----------------\n")
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sample/CMakeLists.txt")
    message("\n----------------sample begin----------------")
    add_subdirectory(./sample/)
    message("---------------- sample end ----------------\n")
endif()