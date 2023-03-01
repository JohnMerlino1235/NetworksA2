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
    MyTHeader* t_head = new MyTHeader();
    char* source = buffer->pointToTHeader();
    memcpy(t_head, source, T_HEAD_LENGTH);
}
// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader() {
}

// checks to see that the checksum was correct
void MyTHeader::check_checksum() {
    cout << "checksum expected " << sAd + dAd + len << endl;
    cout << "checksum actual " << checksum << endl;
    if (checksum != sAd + dAd + len) {
        cout << "Checksum was incorrect!" << endl;
    }
}

// checks to see that the destimation port was correct
void MyTHeader::check_destination_port() {
    cout << "destination expected " << SERVER_ADDRESS << endl;
    cout << "destination actual " << dAd << endl;
    if (dAd != SERVER_ADDRESS) {
        cout << "The destination port is not the local server port!" << endl;
    }
}


