cmake_minimum_required(VERSION 2.6)
project(Worms)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# Set version information in a config.h file
#include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
file(GLOB SOURCES-server
    "src/*.hpp"
    "src/*.cpp"
)
list(REMOVE_ITEM SOURCES-server "src/client_main")
file(GLOB SOURCES-client
    "src/*.hpp"
    "src/*.cpp"
)
list(REMOVE_ITEM SOURCES-client "src/server_main")
add_executable("client" ${SOURCES-client})
add_executable("server" ${SOURCES-server})

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# SFML
set(SFML_ROOT "/usr/lsa")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)
target_link_libraries(client ${SFML_LIBRARIES})

if(SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   target_link_libraries(client ${SFML_LIBRARIES})
endif()


# Install target
install(TARGETS client DESTINATION bin)
install(TARGETS server DESTINATION bin)

# libmicrohttpd
include_directories ("${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/include")
target_link_libraries(server "${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/lib/libmicrohttpd.so")
