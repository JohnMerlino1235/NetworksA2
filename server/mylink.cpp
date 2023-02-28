#include "mylink.h"
#include "mysocket.h"
#include "mydriver.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader() {
}

void MyLHeader::checkLocalAddress() {
    if (dAd != SERVER_ADDRESS) {
        cout << "dAd=" << dAd << endl;
        cout << "incorrect value for dAd myLink" << endl;
    }
}

void MyLHeader::checkTransportProtocol() {
    if (protocol != TRANSPORT_PROTOCOL) {
        cout << "protocol=" << protocol << endl;
        cout << "incorrect value for protocol" << endl;
    }
}

// MyL_rvc is called in MyT_rcv when ready to receive a fragment. 
void MyL_rcv(SkBuf* buffer) {
    driver_rcv(buffer);
    cout << "mylink rcvFrom buffer: " << buffer << endl;
    MyLHeader* l_head = new MyLHeader();
    char* source = buffer->pointToLHeader();
    memcpy(l_head, source, L_HEAD_LENGTH);
    l_head->checkLocalAddress();
    l_head->checkTransportProtocol();
}
