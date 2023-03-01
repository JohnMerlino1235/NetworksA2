#ifndef mytransport_h
#define mytransport_h
#include "mysocket.h"

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
}; 

void MyT_rcv(SkBuf* buffer);


#endif
