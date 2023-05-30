cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  statBase.h statBase.cpp
  gameStats.h gameStats.cpp
  itemBase.h
  itemContainer.h itemContainer.cpp
)

add_executable(testLibRPG
  testLibRPG.cpp)
target_link_libraries(testLibRPG libRPG)
