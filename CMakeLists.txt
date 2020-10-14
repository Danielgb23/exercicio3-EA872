# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(CapivaraMola)

#
add_executable(exer3 src/exercicio3.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(step src/step.cpp)
add_library(view src/view.cpp)
add_library(coord src/coord.cpp)
target_link_libraries(exer3 step)
target_link_libraries(exer3 view)
target_link_libraries(exer3 coord)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Bibliotecas linkadas externamente
target_link_libraries(exer3 SDL2)
target_link_libraries(exer3 SDL2_image)
