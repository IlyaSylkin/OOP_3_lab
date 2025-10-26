cmake_minimum_required(VERSION 3.16)
project(Lab3 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Пути к include
include_directories(include)

# Общие исходники (без main.cpp)
set(CORE_SOURCES
    src/figure.cpp
    src/figure_array.cpp
    src/triangle.cpp
    src/hexagon.cpp
    src/octagon.cpp
)

# Основной исполняемый файл (демонстрация работы)
add_executable(Lab3_exe ${CORE_SOURCES} main.cpp)

# === Google Test ===
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты
set(TEST_SOURCES
    tests/tests_figures.cpp
)

add_executable(Lab3_tests ${CORE_SOURCES} ${TEST_SOURCES})
target_link_libraries(Lab3_tests gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(Lab3_tests)
