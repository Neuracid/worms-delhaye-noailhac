cmake_minimum_required(VERSION 2.6)
project(Worms)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# Set version information in a config.h file
#include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "Main")
file(GLOB SOURCES
    "src/*.hpp"
    "src/*.cpp"
)
add_executable(${EXECUTABLE_NAME} ${SOURCES})


# SFML
set(SFML_ROOT "/usr/lsa")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

if(SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   target_link_libraries(Main ${SFML_LIBRARIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
