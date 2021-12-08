#include "../include/Car.hpp"
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <memory>
#include <math.h>
using namespace std;

Car::Car(){
    this->x_current = rand() % 540 + 40;
    this->y_current = rand() % 380 + 40;
}

Car::~Car(){}

float Car::get_x(){return this->x_current;}
void Car::set_x(float new_x){this->x_current=new_x;}
float Car::get_y(){return this->y_current;}
void Car::set_y(float new_y){this->y_current=new_y;}
float Car::get_angle(){return this->angle;}
void Car::set_angle(float new_angle){this->angle=new_angle;}
float Car::get_speed(){return this->speed;}
void Car::set_speed(float new_speed){this->speed=new_speed;}
float Car::get_maxSpeed(){return this->maxSpeed;}
float Car::get_turnSpeed(){return this->turnSpeed;}
float Car::get_acc(){return this->acc;}
float Car::get_dec(){return this->dec;}