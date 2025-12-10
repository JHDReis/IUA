project(Tests)

add_executable(${PROJECT_NAME} test.cpp
        VectorTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain Utilities)
