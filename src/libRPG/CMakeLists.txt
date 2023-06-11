cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  basicGamedata.hpp
  basicGamedata.cpp
  equipmentSlot.hpp
  gameMetadata.hpp
  gameMetadata.cpp
  player.hpp
  stat.hpp
  statModifyingEntity.hpp
  statModifyingEntity.cpp
)

#ahdd_executable(testLibRPG
#  testLibRPG.cpp)
#target_link_libraries(testLibRPG libRPG)
