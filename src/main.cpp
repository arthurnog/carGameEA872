#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#include <vector>
#include <string>
#include <boost/asio.hpp>
#include <fstream>
#include <iostream>
#include <thread>
#include "../include/json.hpp"
#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include "../include/View.hpp"
#include "../include/Controller.hpp"
#include "../include/Server.hpp"


using namespace std;
using nlohmann::json;
using boost::asio::ip::udp;

std::vector<Car> players;

int main() {
    bool game_on =true;
    SDL_Event event; /* ! eventos discretos */ 
    Server r;
    std::string mensagem_dados;
    json recebido;
    json enviar;
    char tecla[1000];
    int pos = 0;
    
    std::ifstream f;
    int qtd_players=0;

    std::cout << "Qantas pessoas vão jogar ?: \n";
    std::cin >> qtd_players;
    float teste =0;
    teste = (rand()%500);
    std::cout << teste << endl;
    vector<Car> players(qtd_players,Car());
    
    /*for (int i =0; i< qtd_players; i++){
    players[i].set_x(50+(100*i));
    }*/
   
   
    vector<Keyboard> keyboard(qtd_players,Keyboard());

    View view = View(players);

    Controller controller = Controller(keyboard, players);
   
   
  for(int i = 0; i < qtd_players; i++){
        r.conecta();
}

    r.primeiro_envio();

   std::thread t1(&Server::recebe, &r);
   
    
    while(game_on==true){
        controller.polling();
        view.render();



        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game_on = false;
            }
        }








        SDL_Delay(10);
    }


 t1.join();
    return 0;
}
