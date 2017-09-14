cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# In case neither release nor debug is set as build type, default to release.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Third party libraries in lib
#add_subdirectory(external)

# Headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# Source code
add_subdirectory(src)