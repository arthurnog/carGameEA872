#include "../include/Keyboard.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <math.h>
using namespace std;

Keyboard::Keyboard(){
    this->on = true;
    this->u = false;
    this->d = false;
    this->r = false;
    this->l = false;
    this->state = SDL_GetKeyboardState(nullptr);
}
Keyboard::~Keyboard(){}

void Keyboard::input(){
    SDL_PumpEvents();
    if (this->state[SDL_SCANCODE_LEFT]) this->l = true;
    if (this->state[SDL_SCANCODE_RIGHT]) this->r = true;
    if (this->state[SDL_SCANCODE_UP]) this->u = true;
    if (this->state[SDL_SCANCODE_DOWN]) this->d = true;
    while (SDL_PollEvent(&this->event))
    {
        if (this->event.type == SDL_QUIT)
        {
            this->on = false;
        }
    }
}

bool Keyboard::get_on(){return this->on;}
bool Keyboard::get_u(){return this->u;}
bool Keyboard::get_d(){return this->d;}
bool Keyboard::get_r(){return this->r;}
bool Keyboard::get_l(){return this->l;}