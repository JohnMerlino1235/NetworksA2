#include "mysocket.h"
#include "mytransport.h"
#include <cstring>
#include <iostream>
using namespace std;



SkBuf::SkBuf() {
    T_length = T_HEAD_LENGTH;
    cout << "SkBuf T_length" << T_length << endl;
    L_length = L_HEAD_LENGTH;
    cout << "SkBuf L_length" << L_length << endl;
    head = new char[BUFFER_SIZE];
    cout << "SkBuf head" << head << endl;
    message = T_length + L_length + head;
    cout << "SkBuf message" << message << endl;
    message = "helo";
    cout << "SkBuf message" << message << endl;
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

char* SkBuf::getMessage() {
    return message;
}

char* rcvfrom() {
    SkBuf* buffer = new SkBuf();
    MyT_rcv(buffer);
    cout << "mysocket rcvFrom buffer: " << buffer << endl;
    cout << "buffer->getMessage()" << buffer->getMessage();
    return buffer->getMessage();
}
