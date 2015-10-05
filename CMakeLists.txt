cmake_minimum_required (VERSION 2.6)
project (Worms)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(Main src/main.cpp)

# SFML
set(SFML_ROOT "lib/SFML")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules"
${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window system)
if(SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   target_link_libraries(pacman ${SFML_LIBRARIES})
endif()
