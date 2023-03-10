#ifndef mysocket_h
#define mysocket_h
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;

#define BUFFER_SIZE 128
#define T_HEAD_LENGTH 8
#define L_HEAD_LENGTH 12

class SkBuf {
    char * head; //pointer to the first byte of the sent bytes
    char * message; //pointer to the first byte of the message
    int T_length; //Length of Transport layer header
    int L_length; //Length of Link layer header
    int length; //Message length
    short lAd; //Local port
    short fAd; //Foreign por

    public:
        SkBuf();
        char* pointToLHeader();
        char* pointToTHeader();
        char* pointToMessage();
        string getMessage();
        void setLength(int len);
        char* getHead();
};

string rcvfrom();

#endif
