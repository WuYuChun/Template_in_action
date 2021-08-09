cmake_minimum_required(VERSION 2.8.12)
project(Template_In_Action)

set(CMAKE_CXX_STANDARD 17)

file(GLOB CPP_SRC_LIST ./*.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


foreach(v ${CPP_SRC_LIST})
    message(STATUS "the file name is ${v}")
    # file relative path from src/
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" relative_path ${v})
    # string(REGEX MATCH "/.*" relative_path ${v})
    message(STATUS "the file name is ${relative_path}")
    # delete string "src/"
    string(REGEX REPLACE "/" "" target_name ${relative_path})
    # rename '/' and '.' to '_'
    message(STATUS "the file name is ${target_name}")
    string(REGEX REPLACE "/|\\." "_" target_name ${target_name})

    add_executable(${target_name}_cpp ${v})
    target_link_libraries(${target_name}_cpp PRIVATE Threads::Threads)
endforeach()