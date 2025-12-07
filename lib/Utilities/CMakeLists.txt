project(Utilities)

add_library(${PROJECT_NAME} src/Utility.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
