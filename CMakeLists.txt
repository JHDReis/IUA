cmake_minimum_required(VERSION 3.23)

project(IUA)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(3rdparty)
add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(tests)
