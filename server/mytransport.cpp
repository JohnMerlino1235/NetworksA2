#include "mytransport.h"
#include "mysocket.h"
#include "mylink.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


void MyT_rcv(SkBuf* buffer) {
    MyL_rcv(buffer);
    MyTHeader* t_head = new MyTHeader();
    char* source = buffer->pointToTHeader();
    memcpy(t_head, source, T_HEAD_LENGTH);
    t_head->check_checksum();
    t_head->check_destination_port();
    int len = t_head->getLength();
    buffer->setLength(len);
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
    cout << "destination expected " << LOCAL_SERVER_PORT << endl;
    cout << "destination actual " << dAd << endl;
    if (dAd != LOCAL_SERVER_PORT) {
        cout << "The destination port is not the local server port!" << endl;
    }
}

// gets the length of the message
int MyTHeader::getLength() {
    return len;
}

// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader() {
}

