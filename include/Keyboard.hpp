#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#pragma once
using namespace std;

class Keyboard{
    private:
        bool on;
        SDL_Event event;
        const Uint8* state;
    public:
        Keyboard();
        ~Keyboard();
        void polling();
        bool get_on();
};