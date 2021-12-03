cmake_minimum_required(VERSION 3.20)
project(Simulation_ecosystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulation_ecosystem main.cpp Aquarium.cpp Milieu.cpp Bestiole.cpp)

find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
target_link_libraries(Simulation_ecosystem ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})