#include <iostream>
#include <tins/tins.h>

using namespace Tins;
using namespace std;

/*
When you send a port scan with a packet and the FIN flag, you are sending the packet and not expecting a response. 
If you do get an RST you can assume that the port is closed. 
If you get nothing back that indicates the port is open. 
Firewalls are looking for SYN packets, so FIN packets slip through undetected.
*/

int main(int argc, char* argv[]) {
    // The sender
    PacketSender sender;
    // The SYN to be sent.
    IP pkt = IP("#ur IP from ip addr show") / TCP(2000, 1337);
    pkt.rfind_pdu<TCP>().set_flag(TCP::FIN, 1);

    // Send and receive the response.
    std::unique_ptr<PDU> response(sender.send_recv(pkt));
    // Did we receive anything?
    if (response) {
        TCP &tcp = response->rfind_pdu<TCP>();
        if (tcp.get_flag(TCP::RST)) { 
            std::cout << "Port is closed!" << std::endl;
        }
        else {
            std::cout << "Port is open!" << std::endl;
        }
    }
}