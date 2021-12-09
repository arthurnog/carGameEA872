# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(CarCrash)

#
add_executable(CarCrash src/main.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(Car src/Car.cpp)
target_link_libraries(CarCrash Car)
add_library(View src/View.cpp)
target_link_libraries(CarCrash View)
add_library(Keyboard src/Keyboard.cpp)
target_link_libraries(CarCrash Keyboard)
add_library(Controller src/Controller.cpp)
target_link_libraries(CarCrash Controller)
#add_library(receptor src/receptor.cpp)
#target_link_libraries(CarCrash receptor)


# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(CarCrash SDL2)
target_link_libraries(CarCrash SDL2_image)
#target_link_libraries(CarCrash pthread)


