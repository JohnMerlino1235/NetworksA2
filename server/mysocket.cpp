#include "mysocket.h"
#include "mytransport.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;

SkBuf::SkBuf() {
    T_length = T_HEAD_LENGTH;
    L_length = L_HEAD_LENGTH;
    head = new char[BUFFER_SIZE];
    // cout << 'HEAD' << head << endl;
    message = T_length + L_length + head;
    // cout << 'MESSAGE' << message << endl;
    // length = 
}

void SkBuf::setLength(int len) {
    length = len;
}

char* SkBuf::pointToLHeader() {
    char* temp = new char[L_length];
    memcpy(temp, head, L_length);
    return temp;
}

char* SkBuf::pointToTHeader() {
    char* temp = new char[T_length];
    memcpy(temp, head + L_length, T_length);
    return temp;
}

char* SkBuf::getHead() {
    return head;
}

string SkBuf::getMessage() {
    string st(message, length);
    return st;
}

string rcvfrom() {
    SkBuf* buffer = new SkBuf();
    MyT_rcv(buffer);

    // char* temp = new char[T_HEAD_LENGTH];
    // memcpy(temp, buffer->getHead() + L_HEAD_LENGTH + T_HEAD_LENGTH, T_HEAD_LENGTH);

    // char* my_message;
    // memcpy(my_message, temp, T_HEAD_LENGTH);

    // cout << "TEMPPPP" << temp << endl;

    // // char* temp = new char[T_length]
    // // memcpy(buffer->getHead(), st_recv.c_str() + T_HEAD_LENGTH + L_HEAD_LENGTH, st_recv.length());

    return buffer->getMessage();
}
