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
#include "../include/Controller.hpp"

Controller::Controller(vector<Keyboard> &keyboard, vector<Car> &car) : keyboard(keyboard) , car(car) {
    this->on = true;
    this->numPlayers = this->car.size();
}

Controller::~Controller() { SDL_Quit(); }

bool Controller::get_on(){
    return this->on;
}

int Controller::get_numPlayers(){
    return this->numPlayers;
}

void Controller::set_numPlayers(int newNum){
    this->numPlayers = newNum;
}


//a função polling saai daqui e vai para o servidor
void Controller::polling(){
    for(int i = 0; i < this->numPlayers; i++) {
        this->keyboard[i].input();
        if ((this->keyboard[i].get_u()) && (this->car[i].get_speed()) < (this->car[i].get_maxSpeed())){
            if ((this->car[i].get_speed()) < 0) {
                this->car[i].set_speed(this->car[i].get_speed() + this->car[i].get_dec());
            }
        else {
            this->car[i].set_speed(this->car[i].get_speed() + this->car[i].get_acc());
            }
        }

        if ((this->keyboard[i].get_d()) && (this->car[i].get_speed()) > (-1) * (this->car[i].get_maxSpeed())) {
            if ((this->car[i].get_speed()) > 0) {
                this->car[i].set_speed(this->car[i].get_speed() - this->car[i].get_dec());
            }
            else {
                this->car[i].set_speed(this->car[i].get_speed() - this->car[i].get_acc());
            }
        }
        //----------------------------------
        if ((!this->keyboard[i].get_u()) && !((this->keyboard[i].get_d()))) {
            if ((this->car[i].get_speed() - this->car[i].get_dec()) > 0) {
                this->car[i].set_speed(this->car[i].get_speed() - this->car[i].get_dec());
            }
            else if ((this->car[i].get_speed() + this->car[i].get_dec()) < 0) {
                this->car[i].set_speed(this->car[i].get_speed() + this->car[i].get_dec());
            }
            else {
                this->car[i].set_speed(0);
            }
        }

        //-------------------------------------

        if ((this->keyboard[i].get_r()) && (this->car[i].get_speed() != 0)) {
            this->car[i].set_angle((this->car[i].get_angle()) + ((this->car[i].get_turnSpeed()) * ((this->car[i].get_speed()) / (this->car[i].get_maxSpeed()))));
        }

        if ((this->keyboard[i].get_l()) && (this->car[i].get_speed() != 0)) {
            this->car[i].set_angle((this->car[i].get_angle()) - ((this->car[i].get_turnSpeed()) * ((this->car[i].get_speed()) / (this->car[i].get_maxSpeed()))));
        }

        this->car[i].set_x((this->car[i].get_x()) + (sin(this->car[i].get_angle()) * this->car[i].get_speed()));

        this->car[i].set_y((this->car[i].get_y()) - (cos(this->car[i].get_angle()) * this->car[i].get_speed()));

        //-------------------------------------

        if (this->car[i].get_x() < 0) {
        this->car[i].set_x(0);
        }
        if (this->car[i].get_y() < 0) {
            this->car[i].set_y(0);
        }
        if (this->car[i].get_x() > 640) {
            this->car[i].set_x(640);
        }
        if (this->car[i].get_y() > 480) {
            this->car[i].set_y(480);
        }
        this->keyboard[i].reset_input();
        cout << car[i].get_y() << endl;
    }    
}
