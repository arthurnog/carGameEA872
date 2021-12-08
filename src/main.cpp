#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#include <vector>

#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include "../include/View.hpp"
#include "./Car.cpp"
#include "./Keyboard.cpp"
#include "./View.cpp"

using namespace std;

int main() {

    vector<Car> players(2, Car());
    cout << players[1].get_x() << endl;
    players[0].set_x(200);
    players[1].set_x(100);


    View view = View(players);
    Keyboard keyboard = Keyboard();
    while (keyboard.get_on())
    {
        keyboard.input();
        if(keyboard.get_u()){std::cout << "u" << std::endl;}
        if(keyboard.get_d()){std::cout << "d" << std::endl;}
        if(keyboard.get_r()){std::cout << "r" << std::endl;}
        if(keyboard.get_l()){std::cout << "l" << std::endl;}
        view.render();
        keyboard.reset_input();
    }
    SDL_Quit();
    return 0;
}