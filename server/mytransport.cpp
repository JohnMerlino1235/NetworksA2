#include "mytransport.h"
#include "mysocket.h"
#include "mylink.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// The client myA port is 
// chosen during the runtime randomly and the server myA port=65.  

void MyT_rcv(SkBuf* buffer) {
    MyL_rcv(buffer);
    cout << "mytransport rcvFrom buffer: " << buffer << endl;
    MyTHeader* t_head = new MyTHeader();
    char* source = buffer->pointToTHeader();
    memcpy(t_head, source, T_HEAD_LENGTH);
    t_head->checkCheckSum();
    t_head->checkDestinationPort();
}
// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader() {
}

void MyTHeader::checkCheckSum() {
    checksum = sAd + dAd + len;
    if (checksum != sAd + dAd + len) {
        cout << "checksum=" << checksum << endl;
        cout << "incorrect value for checksum" << endl;
    }
}

void MyTHeader::checkDestinationPort() {
    dAd = 1;
    if (dAd != SERVER_PORT_SERVER) {
        cout << "MyTHeader, dAd=" << dAd << endl;
        cout << "incorrect value for destination port" << endl;
    }
}
