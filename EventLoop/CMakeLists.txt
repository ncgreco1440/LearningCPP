cmake_minimum_required(VERSION 3.15)

# Project Name
project(EventLoop VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(EventLoop src/main.cpp)

target_include_directories(EventLoop PUBLIC "${PROJECT_SOURCE_DIR}/include")

# target_include_directories(EventLoop PUBLIC
# 	"${PROJECT_BINARY_DIR}"
# 	"${PROJECT_SOURCE_DIR}/include"
# 	"${PROJECT_SOURCE_DIR}/libs",
# 	"${PROJECT_SOURCE_DIR}/src")

target_link_libraries(EventLoop "${PROJECT_SOURCE_DIR}/libs/nvapi64.lib")

install(TARGETS EventLoop DESTINATION bin)