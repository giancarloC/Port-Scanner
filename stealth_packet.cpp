#include <iostream>
#include <tins/tins.h>

using namespace Tins;
using namespace std;

int main(int argc, char* argv[]) {
    // The sender
    PacketSender sender;
    // The FIN to be sent.
    IP pkt = IP("192.168.0.1") / TCP(22, 1337);
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