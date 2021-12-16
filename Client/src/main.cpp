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
#include <chrono>
#include <sstream>
#include "../include/json.hpp"
#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include "../include/View.hpp"




using namespace std;
using nlohmann::json;
using boost::asio::ip::udp;

std::vector<Car> players;

int main() {
    bool game_on =true;
    SDL_Event event; /* ! eventos discretos */ 

    char mensagem_conexao[1000];
    char dados_recebidos[1000];
    json tec;
    json j;
    int indice;

    std::string dados_enviados;


    std::string mensagem_dados;
    json recebido;
    json enviar;
    char tecla[1000];
    int pos = 0;
    
    std::ifstream f;
    int qtd_players=0;

    std::cout << "Qantas pessoas vão jogar ?: \n";
    std::cin >> qtd_players;
    
    vector<Car> players(qtd_players,Car());
    vector<Keyboard> keyboard(qtd_players,Keyboard());

    View view = View(players); 
    
    boost::asio::io_service io_service;

    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);


// Encontrando IP remoto
    boost::asio::ip::address ip_remoto =
    boost::asio::ip::address::from_string("127.0.0.1"); //25.82.167.175 // 2620:9b::1952:a7af

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
    std::string v("Conectando ao servidor");

    meu_socket.send_to(boost::asio::buffer(v), remote_endpoint);

    Car car1();
    Car car2();
    Car car3();
    Car car4();
    players.push_back(players[0]);
    players.push_back(players[1]);
    players.push_back(players[2]);
    players.push_back(players[3]);
    
    meu_socket.receive_from(boost::asio::buffer(mensagem_conexao,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente

    std::cout<<mensagem_conexao<<std::endl;

    meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente

    

    std::stringstream(dados_recebidos) >> j;
    
    
    for (int i = 0; i < j["indice"]; i++) {
        players[i].set_x(j["car"][i]["x_current"]);
        players[i].set_y(j["car"][i]["y_current"]);
        players[i].set_angle(j["car"][i]["angle"]);
        players[i].set_speed(j["car"][i]["speed"]);
      
             
    }

    
    qtd_players = j["nplayers"];
  

    std::cout << "Conectado" << std::endl;
    
    
    
    
    
    
    /*for (int i =0; i< qtd_players; i++){
    players[i].set_x(50+(100*i));
    }*/
   
   
   

    //Controller controller = Controller(keyboard, players);
    
    while(game_on==true){
        //controller.polling();
        
        meu_socket.send_to(boost::asio::buffer(dados_enviados), remote_endpoint);


        meu_socket.receive_from(boost::asio::buffer(dados_recebidos,1000), // Local do buffer
                                remote_endpoint); // Confs. do Cliente
   
        std::stringstream(dados_recebidos) >> j;

        indice = j["indice"];
        
        for (int i = 0; i < j["indice"]; i++) {
        players[i].set_x(j["car"][i]["x_current"]);
        players[i].set_y(j["car"][i]["y_current"]);
        players[i].set_angle(j["car"][i]["angle"]);
        players[i].set_speed(j["car"][i]["speed"]);
        
             
    }
        
        
        
        
        
        view.render();



        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game_on = false;
            }
        }








        SDL_Delay(10);
    }

    return 0;
}
