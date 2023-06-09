cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
 testLibRPG.cpp
 statModifiers.h statModifiers.cpp
 statModifier.h statModifier.cpp
 stateBase.h stateBase.cpp
 statBase.h statBase.cpp
 gameStats.h gameStats.cpp
 gameMetadata.h gameMetadata.cpp
 equipmentSlots.h equipmentSlots.cpp
 equipmentSlotBase.h equipmentSlotBase.cpp
 basicGameMetadata.h basicGameMetadata.cpp
)

add_executable(testLibRPG
  testLibRPG.cpp)
target_link_libraries(testLibRPG libRPG)
