cmake_minimum_required(VERSION 3.7)

project(Image2Lines)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
FIND_PACKAGE(Boost COMPONENTS program_options system filesystem REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(SOURCE_FILES main.cpp LineSegmentation.hpp LineSegmentation.cpp)

add_executable(Image2Lines ${SOURCE_FILES})
target_link_libraries(Image2Lines ${OpenCV_LIBS} ${Boost_LIBRARIES}   ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
