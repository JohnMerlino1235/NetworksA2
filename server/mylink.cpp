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


// MyL_rvc is called in MyT_rcv when ready to receive a fragment. 
void MyL_rcv(SkBuf* buffer) {
    driver_rcv(buffer);
    MyLHeader* l_head = new MyLHeader();
    char* source = buffer->pointToLHeader();
    memcpy(l_head, source, L_HEAD_LENGTH);
    l_head->check_local_address();
    l_head->check_protocol();
}

// checks to see that the local address was correct
void MyLHeader::check_local_address() {
    cout << "local address expected " << SERVER_ADDRESS << endl;
    cout << "local address actual " << dAd << endl;
    if (dAd != SERVER_ADDRESS) {
        cout << "The destination address doesn't match the server address!" << endl;
    }
}

// checks to see that the protocol was correct
void MyLHeader::check_protocol() {
    cout << "protocol expected " << PROTOCOL << endl;
    cout << "protocol actual " << protocol << endl;
    if (protocol != PROTOCOL) {
        cout << "The protocol is incorrect!" << endl;
    }
}
