#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#include <vector>

#include "../include/Keyboard.hpp"
#include "../include/View.hpp"
#include "../include/Car.hpp"

class Controller {
    private:
        bool on = true;
        vector<Keyboard> &keyboard;
        vector<Car> &car;
        int numPlayers;
    public:
        Controller(vector<Keyboard> &keyboard, vector<Car> &car);
        ~Controller();
        void polling();
        bool get_on();
        int get_numPlayers();
        void set_numPlayers(int newNum);
        void run();
};