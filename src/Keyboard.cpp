#include "../include/Keyboard.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <math.h>
using namespace std;

Keyboard::Keyboard(){
    this->on = true;
    this->state = SDL_GetKeyboardState(nullptr);
}
Keyboard::~Keyboard(){}
void Keyboard::polling(){
    while(this->on){
        SDL_PumpEvents();
        if(state[SDL_SCANCODE_LEFT]){std::cout << "LEFT" << std::endl;}
        if(state[SDL_SCANCODE_RIGHT]){std::cout << "RIGHT" << std::endl;}
        if(state[SDL_SCANCODE_UP]){std::cout << "UP" << std::endl;}
        if(state[SDL_SCANCODE_DOWN]){std::cout << "DOWN" << std::endl;}
    }
}
bool Keyboard::get_on(){return this->on;}