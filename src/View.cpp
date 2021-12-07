#include "../include/Car.hpp"
#include "../include/View.hpp"
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

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

View::View(vector<Car> car){
    // Inicializando o subsistema de video do SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << SDL_GetError();
    }

    // Criando uma janela
    this->window = nullptr;
    this->window = SDL_CreateWindow("Demonstrção de jogo com SDL2",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
    { // Em caso de erro...
        std::cout << SDL_GetError();
        SDL_Quit();
    }

    // Inicializando o renderizador
    this->renderer = SDL_CreateRenderer(
        this->window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == nullptr)
    { // Em caso de erro...
        SDL_DestroyWindow(this->window);
        std::cout << SDL_GetError();
        SDL_Quit();
    }

    numPlayers = this->car.size();
    
    this->background = IMG_LoadTexture(renderer, "../assets/arena.png");
    for (int i=0;i<numPlayers;i++){
        this->carSprite.push_back(IMG_LoadTexture(renderer, "../assets/car.png"));
    }
    SDL_Rect aux;
    for (int i=0;i<numPlayers;i++){
        aux.x = this->car[i].get_x();
        aux.y = this->car[i].get_y();
        this->carTarget.push_back(aux);
        SDL_QueryTexture(this->carSprite[i], nullptr, nullptr, &(this->carTarget[i].w), &(this->carTarget[i].h));
    }
}

View::~View(){
    for (int i=0;i<numPlayers;i++){
        SDL_DestroyTexture(this->carSprite[i]);
    }
    SDL_DestroyTexture(this->background);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int View::get_numPlayers(){ return this->numPlayers; }
void View::set_numPlayers(int newNum){ this->numPlayers = newNum; }

void View::add_newCar(Car &newCar){
    this->car.push_back(newCar);
    this->carSprite.push_back(IMG_LoadTexture(renderer, "../assets/car.png"));
    SDL_Rect aux;
    aux.x = newCar.get_x();
    aux.y = newCar.get_y();
    this->carTarget.push_back(aux);
    SDL_QueryTexture(this->carSprite[this->numPlayers], nullptr, nullptr, &(this->carTarget[this->numPlayers].w), &(this->carTarget[this->numPlayers].h));
    set_numPlayers(this->numPlayers +1);
}

void View::render(){

    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->background, nullptr, nullptr);

    for(int i = 0; i < this->numPlayers; i++){
        this->carTarget[i].x = car[i].get_x();
        this->carTarget[i].y = car[i].get_y();
        SDL_RenderCopyEx(this->renderer, this->carSprite[i], nullptr, &(this->carTarget[i]), this->car[i].get_angle()*(180/3.141592), NULL, SDL_FLIP_NONE);
    }

    SDL_RenderPresent(this->renderer);
    SDL_Delay(10);

}