#ifndef mylink_h
#define mylink_h

#include "mysocket.h"

#define SERVER_ADDRESS 32
#define TRANSPORT_PROTOCOL 77

class MyLHeader{ 
    private: 
    //Data members here 
        int sAd;
        int dAd;
        int protocol;

    public: 
    //Constructor/s, Destructor and methods here 
        MyLHeader();
        void checkLocalAddress();
        void checkTransportProtocol();
        void printValues();
}; 
 
 void MyL_rcv(SkBuf* buffer);

 #endif
