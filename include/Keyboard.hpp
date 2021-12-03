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
        bool u;
        bool d;
        bool r;
        bool l;

    public:
        Keyboard();
        ~Keyboard();
        void input(); //checa inputs do teclado, no caso as setas
        bool get_on();
        bool get_u();
        bool get_d();
        bool get_r();
        bool get_l();
        void reset_input(); //Reseta os booleans referente aos inputs apos serem usados
};