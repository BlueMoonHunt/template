cmake_minimum_required(VERSION 3.26.0)
project(template VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES src/*.c src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)