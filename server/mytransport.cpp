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

