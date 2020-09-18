#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {

    const regex ipRegex("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    bool running = true
    //while running
      //prompt ip input (string)
      //if they are done, running false
      //else
        //check valid ip (using regex, dw if you don't know it)
        bool valid = regex_match(ip, ipRegex);
        //if valid
          //prompt range (int)
          //call portscan with ip and range
        //else, messgae + continue
    //closing messgae
  return 0;
}

//scanning function here - needs concurrency and stealth
int portscan(string ip, int range){

  for(int port = 0; port <= range; port++){
    if(port_is_open(ip,port)){
      cout << "Port " << port << " is open." << '\n';
    }
  }

  return 0;
}

//checks if socket is open
bool port_is_open(const std::string& ip, int port)
{
    sf::TcpSocket socket;
    bool open = (socket.connect(sf::IpAddress(ip), port) == sf::Socket::Done);
    socket.disconnect();
    return open;
}