#ifndef mylink_h
#define mylink_h
#include "mysocket.h"

#define SERVER_ADDRESS 32
#define PROTOCOL 53
#define L_HEAD_LENGTH 12

class MyLHeader{ 
    private: 
        // Data members here
        int protocol;
        int sAd;
        int dAd;
    public: 
        // Constructor and destructor and methods here 
        MyLHeader(short src)
        ~MyLHeader();
}; 

void myL_send(SkBuf* buffer);

#endif
