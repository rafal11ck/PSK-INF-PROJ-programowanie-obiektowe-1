cmake_minimum_required(VERSION 3.22.1)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE)
  include(${wxWidgets_USE_FILE})
endif()

add_executable(ksprpg
aplikacjaApp.cpp
aplikacjaApp.hpp
aplikacjaGM.cpp
aplikacjaGM.hpp
aplikacjaMain.cpp
aplikacjaMain.hpp
aplikacjaPlayer.cpp
aplikacjaPlayer.hpp)
target_link_libraries(ksprpg rpglib ${wxWidgets_LIBRARIES})
