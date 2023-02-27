#include "mylink.h"
#include "mysocket.h"
#include "mydriver.h"

void myL_send(SkBuf* buffer) {
    MyLHeader* lHeader = new MyLHeader(buffer->get_local_port());
    buffer->add_LHeader((char*)lHeader);
    driver_send(buffer);
}

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader(short src) {
    sAd = (int)src;
    dAd = SERVER_ADDRESS;
    protocol = PROTOCOL;
}  

// ~MyLHeader is the destructor for the MyLHeader class
MyLHeader::~MyLHeader() {
}
