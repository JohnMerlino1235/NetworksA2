#include "mysocket.h"
#include "mytransport.h"
#include <cstring>



SkBuf::SkBuf() {
    T_length = T_HEAD_LENGTH;
    L_length = L_HEAD_LENGTH;
    head = new char[BUFFER_SIZE];
    message = T_length + L_length + head;
}

char* SkBuf::pointToLHeader() {
    char* temp = new char[L_length];
    memcpy(temp, head, L_length);
    return temp;
}

char* SkBuf::pointToTHeader() {
    char* temp = new char[T_length];
    memcpy(temp, head, T_length);
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
    return buffer->getMessage();
}
