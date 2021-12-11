#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#include <vector>

#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include "../include/View.hpp"
#include "../include/Controller.hpp"


using namespace std;

int main() {

    vector<Car> players(2, Car());
    players[0].set_x(200);
    players[1].set_x(100);
    vector<Keyboard> keyboard(2,Keyboard());

    View view = View(players);

    Controller controller = Controller(keyboard, players);
    
    while(true){
        controller.polling();
        view.render();

        SDL_Delay(10);
    }

    return 0;
}