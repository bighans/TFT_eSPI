
cmake_minimum_required(VERSION 3.25)
set (CMAKE_CXX_STANDARD 20)
include(FetchContent)

# This is the way.
project(Bodmer_Master LANGUAGES C CXX)

if(APPLE)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(FOUNDATION_LIBRARY Foundation)
endif()

if(UNIX AND NOT APPLE)
    # If Linux, add rt and pthread
    set(rt_LIBRARIES rt)
    set(pthread_LIBRARIES pthread)
endif()

if( EXISTS /dev/spidev0.0)
	message(STATUS "SPI exists")
	add_compile_definitions(RASPBIANSPI)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
# set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

# Get all the source codes
file(GLOB BODMERSRC
       ${PROJECT_SOURCE_DIR}/*.cpp
	   ${PROJECT_SOURCE_DIR}/*.c
	   ${PROJECT_SOURCE_DIR}/Piduino/*.c
	   ${PROJECT_SOURCE_DIR}/Piduino/*.cpp
)
add_executable(Bodmer_Master ${BODMERSRC})

target_include_directories(Bodmer_Master PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/
	${CMAKE_CURRENT_SOURCE_DIR}/Piduino/
    /usr/local/include
    /opt/vcpkg/installed/arm64-osx/include)

if(APPLE)
	target_link_libraries(Bodmer_Master ${FOUNDATION_LIBRARY} ${IOKIT_LIBRARY})
elseif(UNIX)
	target_link_libraries(Bodmer_Master pigpio pthread rt )
else()
	target_link_libraries(Bodmer_Master setupapi)
endif()
