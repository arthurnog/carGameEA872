# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Client)

#
add_executable(Client src/main.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(Car src/Car.cpp)
target_link_libraries(Client Car)
add_library(View src/View.cpp)
target_link_libraries(Client View)
add_library(Keyboard src/Keyboard.cpp)
target_link_libraries(Client Keyboard)
add_library(Controller src/Controller.cpp)
target_link_libraries(Client Controller)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(Client SDL2)
target_link_libraries(Client SDL2_image)
target_link_libraries(Client pthread)
