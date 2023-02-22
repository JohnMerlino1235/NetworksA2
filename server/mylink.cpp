#include "mylink.h"
#include "mysocket.h"
#include "mydriver.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader() {
    cout << "MyLHeader server constructor" << endl;
}

void MyLHeader::checkLocalAddress() {
    if (dAd != SERVER_ADDRESS) {
        cout << "incorrect value for dAd" << endl;
    }
}

void MyLHeader::checkTransportProtocol() {
    if (protocol != TRANSPORT_PROTOCOL) {
        cout << "incorrect value for protocol" << endl;
    }
}

void MyLHeader::printValues() {
    cout << "sAd=" << sAd << " dAd=" << dAd << " protocol=" << protocol << endl;
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