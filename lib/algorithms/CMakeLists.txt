cmake_minimum_required(VERSION 3.23)
project(Algorithms)

add_library(${PROJECT_NAME}
        src/Utility.cpp
        src/StopWatch.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_26)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)