cmake_minimum_required(VERSION 3.8)

project(EditionFaker)

add_library(EditionFaker SHARED)

target_sources(EditionFaker PRIVATE "EditionFaker.cpp" "Memory.h")

add_subdirectory(minhook)

target_link_libraries(EditionFaker PRIVATE minhook)
