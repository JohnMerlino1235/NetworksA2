#include "mylink.h"
#include "mysocket.h"
#include "mydriver.h"
#include <iostream>
#include <stdlib.h>

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader(short src, char* head) {
    sAd = (int)src;
    dAd = SERVER_ADDRESS;
    protocol = PROTOCOL;
    memcpy(head, &sAd, 4);
    memcpy(head + 4, &dAd, 4);
    memcpy(head + 8, &protocol, 4);
}  

// ~MyLHeader is the destructor for the MyLHeader class
MyLHeader::~MyLHeader() {
}

// 
void myL_send(SkBuf* buffer) {
    char* head = buffer->get_head();
    MyLHeader* lHeader = new MyLHeader(buffer->get_local_port(), head);
    driver_send(buffer);
}