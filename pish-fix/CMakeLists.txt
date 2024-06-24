cmake_minimum_required(VERSION 3.10)
project(MyLibrary)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-g)

# ЗДЕСЬ ПИШЕМ СВОИ ИСХОДНИКИ
set(SOURCE_FILES
    src/my_class.cpp
)

# Чтобы можно было везде писать #include "my_class.h" без указания полного пути
include_directories(src)

# Если хотите хранить хедеры в другой папке (например, headers), то можно указать путь до них
# include_directories(headers)

# Собираем нашу библиотеку
add_library(MyLibrary ${SOURCE_FILES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# ЗДЕСЬ ПИШЕМ СВОИ ТЕСТЫ
add_executable(
  my_class_test # имя теста, можно любое (но если поменяли, то дальше нужно тоже изменить)
  # А вот тут указываем файл
  tests/test_my_class.cpp
)
# p.s. скомпиллированный тест будет лежать в build по имени теста

# здесь подвязывается gtest
target_link_libraries(
  my_class_test
  GTest::gtest_main
)

# здесь к тесту подвязывается наша либа
target_link_libraries(
  my_class_test
  MyLibrary
)
