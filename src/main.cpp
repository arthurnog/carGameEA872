#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>

#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include "./Keyboard.cpp"

//deleetar depois
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    //deletar depois
    // Criando uma janela
    SDL_Window* window = nullptr;
    window = SDL_CreateWindow("Demonstracao do SDL2",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (window==nullptr) { // Em caso de erro...
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }

    // Inicializando o renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer==nullptr) { // Em caso de erro...
        SDL_DestroyWindow(window);
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }


    Keyboard keyboard = Keyboard();
    while (keyboard.get_on())
    {
        keyboard.input();
        if(keyboard.get_u()){std::cout << "u" << std::endl;}
        if(keyboard.get_d()){std::cout << "d" << std::endl;}
        if(keyboard.get_r()){std::cout << "r" << std::endl;}
        if(keyboard.get_l()){std::cout << "l" << std::endl;}
        keyboard.reset_input();

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}