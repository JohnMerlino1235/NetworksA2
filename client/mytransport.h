#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class MyTHeader{ 
    private: 
        short sAd; //source port
        short dAd;  //destination port
        short len;   //length in bytes of MyA message
        short checksum; // Error detection control only for MyT header. The Checksum field is the 
                        // sum of the Source port, Destination port and Length fields. 
    public: 
        MyTHeader(short in_len);
        ~MyTHeader();
        //Constructor/s, Destructor and methods here 
        //At least, this contains the following function: 
        // MyT_send(...) → called in sendto to send a segment 
        void MyT_send(/*fill in later*/);
}; 