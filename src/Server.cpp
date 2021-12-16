#include "../include/Server.hpp"
#include <sstream>
#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include <boost/asio.hpp>
#include "../include/json.hpp"
#include <iostream>
#include <string>
#include <vector>

using boost::asio::ip::udp;
using nlohmann::json;
std::vector<udp::endpoint> endereco;
extern std::vector<Car> players;




Server::Server(){

}


void Server::conecta() {
vector<Car> players(1,Car());

    Car car1();
    Car car2();
    Car car3();
    Car car4();
 
    char v[120];

    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                    // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                            local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar


    my_socket.receive_from(boost::asio::buffer(v,120), // Local do buffer
                        remote_endpoint); // Confs. do Cliente

    std::cout << v << std::endl;
    std::cout << "Fim de mensagem!" << std::endl;


    // Respondendo a mensagem
    std::string msg("Recebido! Obrigado, cambio e desligo!");
    my_socket.send_to(boost::asio::buffer(msg), remote_endpoint);

    std::cout << "Mensagem de retorno enviada" << std::endl;

    if(endereco.size() == 0){
        endereco.push_back(remote_endpoint);
        players.push_back(players[0]);
    }
    else if(endereco.size() == 1 && remote_endpoint != endereco[0]){
        endereco.push_back(remote_endpoint);
        players.push_back(players[1]);
    }
    else if(endereco.size() == 2 && remote_endpoint != endereco[0] && remote_endpoint != endereco[1]){
        endereco.push_back(remote_endpoint);
        players.push_back(players[3]);
    }
    else if(endereco.size() == 3 && remote_endpoint != endereco[0] && remote_endpoint != endereco[1] && remote_endpoint != endereco[2]){
        endereco.push_back(remote_endpoint);
        players.push_back(players[4]);
    }
}

void Server::primeiro_envio() {
    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                        // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                                local_endpoint); // endpoint

    json enviar;
    std::string mensagem_dados;

    for (int k = 0; k < endereco.size(); k++) {
        enviar["nplayers"] = players.size();
        enviar["k"] = k;
        enviar["car"][k]["x_current"]= players[k].get_x();
        enviar["car"][k]["y_current"] = players[k].get_y();
        enviar["car"][k]["angle"] = players[k].get_angle();
        enviar["car"][k]["speed"] = players[k].get_speed();
        

       
        mensagem_dados = enviar.dump();
        my_socket.send_to(boost::asio::buffer(mensagem_dados), endereco[k]);
    }
}


void Server::recebe() {
    char tecla[1000];
    bool on = 1;
    int l = 0;
    json recebido;
    json enviar;
    std::string mensagem_dados;
    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                        // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service, // io service
                                local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar



    while (on) {
        my_socket.receive_from(boost::asio::buffer(tecla,1000), // Local do buffer
                        remote_endpoint); // Confs. do Cliente
        
        std::stringstream(tecla) >> recebido;

        for(int i=0; i<endereco.size(); i++) {
            if(endereco[i] == remote_endpoint) {
                l = i;
            }
        }
        
        //players[l].set_direcao(recebido["tecla"]);
    
        for ( int i =0; i < players.size();i++){
           
            enviar["nplayers"] = players.size();
        enviar["i"] = i;
        enviar["car"][i]["x_current"]= players[i].get_x();
        enviar["car"][i]["y_current"] = players[i].get_y();
        enviar["car"][i]["angle"] = players[i].get_angle();
        enviar["car"][i]["speed"] = players[i].get_speed();
            mensagem_dados = enviar.dump();
            my_socket.send_to(boost::asio::buffer(mensagem_dados), endereco[i]);
        }
         

    }

}



