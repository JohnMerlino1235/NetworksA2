#include "mytransport.h"
#include "mylink.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader(short in_len) {
    //Source port: identifies the application sending the segment. It is the client port number (random between 2 and 30000). 
    // Providing a seed value
	srand((unsigned) time(NULL));
    // get a random number
    short randomPortNumber = 2 + (rand() % 30000);
    // Destination port: identifies the application which is the destination of the segment (always 65)
    dAd = (short)SERVER_PORT;
    // the length of the message
    len = (short)in_len;
    //Checksum: Error detection control only for MyT header. The Checksum is the sum of the source port, destination port, and length
    checksum = (short)(sAd + dAd + len);
}

// ~MyTHeader represents the desctuctor for a MyTHeader class
MyTHeader::~MyTHeader() {
}

// MyT_send is called in sendto to send a segment 
void myT_send(SkBuf* buffer) {
    MyTHeader* tHeader = new MyTHeader(buffer->get_message_length());
    buffer->add_THeader((char*)tHeader);
    cout << "buffer -> get_message_length " << buffer->get_head() << endl;
    myL_send(buffer);
}
