#include <memory>
#include "../include/Car.hpp"
#include "../include/Keyboard.hpp"
#include <vector>
#include <fstream>
#include <boost/asio.hpp>
#pragma once

using boost::asio::ip::udp;
extern std::vector<udp::endpoint> endereco;
extern std::vector<Car> players;
class Server {
    private:
        
        
    public:
        Server();
        void recebe();
        void conecta();
        void primeiro_envio();

};
