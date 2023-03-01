#include "mysocket.h"
#include "mytransport.h"
#include "mylink.h"
#include <cstring>
#include <iostream>

using namespace std;

//Tx path: m is the message and fA is the destination port
SkBuf::SkBuf(string m, short fA) {
    length = m.size();
    T_length = T_HEAD_LENGTH;
    L_length = L_HEAD_LENGTH;
    head = new char[length + T_length + L_length]; 
    message = head + T_length + L_length; 
    lAd = LOCAL_PORT_ADDRESS;
    fAd = fA;
    memcpy(message, m.c_str(), length);
    // memcpy(message + 24, m, length);
}

SkBuf::~SkBuf() {

}

void send_to(string message) {
    SkBuf* buffer = new SkBuf(message, SERVER_ADDRESS);
    cout << "MESSAGE IN SEND TO" << message << endl;

    string st(buffer->get_head() + 20, 100);
    cout << "HERE... " << st << endl;

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