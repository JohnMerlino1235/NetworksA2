#ifndef mytransport_h
#define mytransport_h
#include "mysocket.h"

#define SERVER_PORT 65
#define T_HEAD_LENGTH 8

class MyTHeader{ 
    private: 
        short sAd; //source port
        short dAd;  //destination port
        short len;   //length in bytes of MyA message
        short checksum; // Error detection control only for MyT header. The Checksum field is the 
                        // sum of the Source port, Destination port and Length fields. 
    public:
        MyTHeader(short in_len, char* head);
        ~MyTHeader();
}; 

void myT_send(SkBuf* buffer);

#endif
