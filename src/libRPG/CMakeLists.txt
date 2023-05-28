cmake_minimum_required(VERSION 3.26.3)

add_library(libRPG gameMetadata.hpp gameMetadata.hpp gameStat.hpp gameStat.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testLibRPG testLibRPG.cpp)
target_link_libraries(testLibRPG libRPG)
