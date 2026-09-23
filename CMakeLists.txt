cmake_minimum_required (VERSION 3.10)

project ("NEBJI")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_subdirectory(engine)