cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  basicGamedata.hpp
  basicGamedata.cpp
  equipmentSlot.hpp
  equipmentSlot.cpp
  gameMetadata.hpp
  gameMetadata.cpp
  character.hpp
  character.cpp
  stat.hpp
  stat.cpp
  statModifyingEntity.hpp
  statModifyingEntity.cpp
)


add_executable(test test.cpp)
target_link_libraries(test libRPG)
