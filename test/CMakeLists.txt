cmake_minimum_required(VERSION 3.10)
project(test
    DESCRIPTION "test project"
)

enable_testing()

add_subdirectory(regress)

add_subdirectory(unit)

add_subdirectory(speed)
