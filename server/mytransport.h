#ifndef mytransport_h
#define mytransport_h

#include "mysocket.h"

#define SERVER_PORT_SERVER 1

class MyTHeader{ 
    private: 
        short sAd; //source port
        short dAd;  //destination port
        short len;   //length in bytes of MyA message
        short checksum; // Error detection control only for MyT header. The Checksum field is the 
                        // sum of the Source port, Destination port and Length fields. 
    public: 
        //Constructor/s, Destructor and methods here 
        MyTHeader();
        void checkCheckSum();
        void printValues();
        void checkDestinationPort();
}; 

void MyT_rcv(SkBuf* buffer);


#endif