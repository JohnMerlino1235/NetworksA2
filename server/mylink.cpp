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
}
