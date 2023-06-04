cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  statBase.h statBase.cpp
  gameStats.h gameStats.cpp
  equipmentSlotBase.h equipmentSlotBase.cpp
  equipmentSlots.h equipmentSlots.cpp
)

add_executable(testLibRPG
  testLibRPG.cpp)
target_link_libraries(testLibRPG libRPG)
