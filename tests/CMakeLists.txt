cmake_minimum_required(VERSION 2.6)

#Project definition
project(SZE-MOSZE-2020-Merida_dualthrust)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test
# and the GTest and pthread library
add_executable( runTests Tests.cpp )
target_link_libraries(runTests gtest gtest_main pthread)
target_compile_features(runTests PRIVATE cxx_std_17)