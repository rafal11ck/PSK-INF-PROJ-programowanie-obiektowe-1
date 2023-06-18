cmake_minimum_required(VERSION 3.22.1)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE)
  include(${wxWidgets_USE_FILE})
endif()

add_executable(app
appApp.cpp
appApp.hpp
appGM.cpp
appGM.hpp
appMain.cpp
appMain.hpp
appPlayer.cpp
appPlayer.hpp
)
target_link_libraries(app libRPG ${wxWidgets_LIBRARIES})
