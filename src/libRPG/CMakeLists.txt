cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  basicGamedata.hpp
  basicGamedata.cpp
  character.hpp
  character.cpp
  equipmentSlot.hpp
  equipmentSlot.cpp
  gameData.hpp
  gameData.cpp
  gameMetadata.hpp
  gameMetadata.cpp
  item.hpp
  item.cpp
  stat.hpp
  stat.cpp
  statModifyingEntity.hpp
  statModifyingEntity.cpp
)


add_executable(test test.cpp)
target_link_libraries(test libRPG)
