#include "mylink.h"
#include "mysocket.h"
#include "mydriver.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader() {
    protocol = TRANSPORT_PROTOCOL;
}

void MyLHeader::checkLocalAddress() {
    if (dAd != SERVER_ADDRESS) {
        cout << "dAd=" << dAd << endl;
        cout << "incorrect value for dAd myLink" << endl;
    }
}

void MyLHeader::checkTransportProtocol() {
    protocol = 53;
    if (protocol != TRANSPORT_PROTOCOL) {
        cout << "protocol=" << protocol << endl;
        cout << "incorrect value for protocol" << endl;
    }
}

// MyL_rvc is called in MyT_rcv when ready to receive a fragment. 
void MyL_rcv(SkBuf* buffer) {
    driver_rcv(buffer);
    MyLHeader* head = new MyLHeader();
    char* source = buffer->pointToLHeader();
    memcpy(head, source, L_HEAD_LENGTH);
    head->checkLocalAddress();
    head->checkTransportProtocol();
}
