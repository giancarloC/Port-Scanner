#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {

  const regex ipRegex("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
  bool running = true;  
  string ip;
  int range;
  
  // Since we're taking both command line inputs and user inputs, I think this part has to be incorporated with the skeleton code below
  /*  
  // If IP and range is given as command line arguments
  if (argc == 3){
    ip = argv[1];
    range = stoi(argv[2]);
  }    
  else {  }
  */
  
  //while running
  while (running){
    //prompt ip input (string)               
    std::cout << "Enter IP Address (q to quit): " << endl;
    std::cin >> ip;

    //if they are done, running false
    if (ip == "q") {         
      running = false;
    }
    //else
    else {        
      //check valid ip (using regex, dw if you don't know it)
      bool valid = regex_match(ip, ipRegex);
      //if valid
      if (valid) {
        //prompt range (int)        
        std::cout << "Valid IP Address." << endl << "Enter the range of ports to scan: " << endl;
        std::cin >> range;

        //call portscan with ip and range
        portscan(ip, range);
      }
      else {
      //else, message + continue
      std::cout << "Invalid IP Address." << endl;  
      }
    }
  }  
  //closing message 
  std::cout << "Exiting program." << endl;
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
