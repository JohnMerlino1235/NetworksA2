#ifndef mytransport_h
#define mytransport_h
#include "mysocket.h"

#define LOCAL_SERVER_PORT 65

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
        void check_checksum();
        void check_destination_port();
        int getLength();
}; 

void MyT_rcv(SkBuf* buffer);


#endif
