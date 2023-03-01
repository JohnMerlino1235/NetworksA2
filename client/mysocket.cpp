#include "mysocket.h"
#include "mytransport.h"
#include "mylink.h"
#include <cstring>
#include <iostream>

using namespace std;

//Tx path: m is the message and fA is the destination port
SkBuf::SkBuf(char* m, short fA) {
    head = new char[length + T_length + L_length]; 
    message = head + T_length + L_length; 
    T_length = T_HEAD_LENGTH;
    L_length = L_HEAD_LENGTH;
    length = strlen(m);
    lAd = LOCAL_PORT_ADDRESS;
    fAd = fA;

    memcpy(message, m, length); 
}

SkBuf::~SkBuf() {

}

void send_to(char* message) {
    SkBuf* buffer = new SkBuf(message, SERVER_ADDRESS);
    myT_send(buffer);
}

int SkBuf::get_message_length() {
    return length;
}

short SkBuf::get_local_port() {
    return lAd;
}

char* SkBuf::get_head() {
    return head;
}

int SkBuf::get_head_length() {
    return length + T_length + L_length;
}

void SkBuf::add_THeader(char* tSegment) {
    memcpy(tSegment, head + L_length, T_length);
}

void SkBuf::add_LHeader(char* lSegment) {
    memcpy(lSegment, head, L_length);
}
