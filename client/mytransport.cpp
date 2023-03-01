#include "mytransport.h"
#include "mylink.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader(short in_len, char* head) {
    //Source port: identifies the application sending the segment. It is the client port number (random between 2 and 30000). 
    // Providing a seed value
	srand((unsigned) time(NULL));
    // get a random number
    short sAd = 2 + (rand() % 30000);
    // Destination port: identifies the application which is the destination of the segment (always 65)
    dAd = (short)SERVER_PORT;
    // the length of the message
    len = (short)in_len;
    //Checksum: Error detection control only for MyT header. The Checksum is the sum of the source port, destination port, and length
    checksum = (short)(sAd + dAd + len);
    memcpy(head + L_HEAD_LENGTH, &sAd, 2);
    memcpy(head + L_HEAD_LENGTH + 2, &dAd, 2);
    memcpy(head + L_HEAD_LENGTH + 4, &len, 2);
    memcpy(head + L_HEAD_LENGTH + 6, &checksum, 2);
}

// ~MyTHeader represents the desctuctor for a MyTHeader class
MyTHeader::~MyTHeader() {
}

// MyT_send is called in sendto to send a segment 
void myT_send(SkBuf* buffer) {
    char* head = buffer->get_head();
    MyTHeader* tHeader = new MyTHeader(buffer->get_message_length(), head);
    myL_send(buffer);
}