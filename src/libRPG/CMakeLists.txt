cmake_minimum_required(VERSION 3.22.1)

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
  state.cpp
  state.hpp
  statModifyingEntity.hpp
  statModifyingEntity.cpp
)

add_subdirectory(tests)
