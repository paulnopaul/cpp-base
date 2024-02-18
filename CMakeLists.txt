cmake_minimum_required(VERSION 3.26)
project(hse_cpp_spring_2024)

set(CMAKE_CXX_STANDARD 14)

# Указываем путь к установленным заголовочным файлам Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Указываем путь к исходным файлам
add_executable(hse_cpp_spring_2024
        01/allocator.cpp
        01/allocator.h
        01/test.cpp)

# Линкуем библиотеки Google Test
target_link_libraries(hse_cpp_spring_2024 ${GTEST_LIBRARIES} pthread)
