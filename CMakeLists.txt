cmake_minimum_required(VERSION 3.15)
project(InternshipExercises)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
set(CMAKE_CXX_STANDARD 20)

add_executable(InternshipExercises main.cpp SelfOrganizingList.hpp)
add_library(Morphs SHARED Morphs.hpp Morphs.cpp)
target_link_libraries(InternshipExercises PUBLIC Morphs)
