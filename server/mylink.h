#ifndef mylink_h
#define mylink_h

#include "mysocket.h"

#define SERVER_ADDRESS 65
#define TRANSPORT_PROTOCOL 53

class MyLHeader{ 
    private: 
    //Data members here 
        int sAd;
        int dAd;
        int protocol;
    public: 
    //Constructor/s, Destructor and methods here 
        MyLHeader();
        void check_local_address();
        void check_protocol();
}; 
 
 void MyL_rcv(SkBuf* buffer);

 #endif
