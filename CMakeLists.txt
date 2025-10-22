cmake_minimum_required(VERSION 3.10)

project(lab3 
    VERSION 1.0.0
    DESCRIPTION "Лабораторная работа 3: Геометрические фигуры"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE LIBRARY_SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab3_lib ${LIBRARY_SOURCES})

add_executable(lab3_main main.cpp)

target_link_libraries(lab3_main PRIVATE lab3_lib)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lab3_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(lab3_main PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab3_tests ${TEST_DIR}/test.cpp)

target_link_libraries(lab3_tests PRIVATE lab3_lib gtest_main)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lab3_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(MINGW)
    add_custom_command(TARGET lab3_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:gtest>"
        $<TARGET_FILE_DIR:lab3_tests>
    )
    add_custom_command(TARGET lab3_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:gtest_main>"
        $<TARGET_FILE_DIR:lab3_tests>
    )
endif()

include(GoogleTest)
gtest_discover_tests(lab3_tests)