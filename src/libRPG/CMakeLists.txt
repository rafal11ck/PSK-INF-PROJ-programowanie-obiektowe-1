cmake_minimum_required(VERSION 3.26.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(libRPG
  gameMetaData.hpp
  gameMetaData.cpp
  basicGamedata.hpp
  #basicGamemetadata.cpp
  stat.hpp
)

#ahdd_executable(testLibRPG
#  testLibRPG.cpp)
#target_link_libraries(testLibRPG libRPG)
