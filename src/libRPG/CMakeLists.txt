cmake_minimum_required(VERSION 3.26.3)

add_library(libRPG
  gameMetadata.h gameMetadata.cpp
  gameStat.h gameStat.cpp
  item.h
  gameData.h gameData.cpp
  itemHolder.h itemHolder.cpp
)

add_executable(testLibRPG
  testLibRPG.cpp)

target_link_libraries(testLibRPG libRPG)
