#include <iostream>
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
          //run scan function on ip
        //else, messgae + continue
    //closing messgae
  return 0;
}

//concurrently scanning function here - input: IP
int portscan(ip){


  return 0;
}
