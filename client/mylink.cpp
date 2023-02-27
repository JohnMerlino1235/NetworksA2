#include "mylink.h"
#include "mysocket.h"

void myL_send(SkBuf* buffer) {
    MyLHeader* lHeader = new MyLHeader(buffer->get_local_port());
    buffer->add_LHeader((char*)lHeader);
    driver_send(buffer);
}

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader(short src) {
    protocol = (int)PROTOCOL;
    sAd = (int)src;
    dAd = (int)SERVER_ADDRESS;
}  

// ~MyLHeader is the destructor for the MyLHeader class
MyLHeader::~MyLHeader() {
}