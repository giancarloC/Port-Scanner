#include <iostream>
#include <tins/tins.h>

using namespace Tins;
using namespace std;

// The sender
PacketSender sender;
// The SYN to be sent.
IP pkt = IP("192.168.0.1") / TCP(22, 1337);
pkt.rfind_pdu<TCP>().set_flag(TCP::SYN, 1);

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