#pragma once
#include "../include/Car.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <vector>
#include <memory>
#include <math.h>
#include <iostream>
#include <memory>
using namespace std;

class View
{
private:
    vector<Car> &car;
    SDL_Renderer* renderer;
    SDL_Window* window;
    vector<SDL_Rect> carTarget;
    vector<SDL_Texture *> carSprite;
    SDL_Texture *background;
    int numPlayers;
    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

public:
    View(vector<Car> &car);
    ~View();
    void render();
    int get_numPlayers();
    void set_numPlayers(int newNum);
    void add_newCar(Car &newCar);
};