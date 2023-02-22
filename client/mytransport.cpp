#include "mytransport.h"

// The client myA port is 
// chosen during the runtime randomly and the server myA port=65.  

// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader(short in_len) {
    cout << "Constructor for Client MyTHeader class" << endl;
    //Source port: identifies the application sending the segment. It is the client port 
    //number, which is chosen randomly between 2 and 30000 in the client. 

    // Providing a seed value
	srand((unsigned) time(NULL));
    // get a random number
    short randomPortNumber = 2 + (rand() % 30000);
    sAd = randomPortNumber;

    // Destination port:
    // identifies the application which is the destination of the segment. 
    // In our case it is always the server port =65
    dAd = 65;

    len = in_len;

    //Checksum: Error detection control only for MyT header. The Checksum field is the 
    // sum of the Source port, Destination port and Length fields.  
    checksum = sAd + dAd + len;
}

// ~MyTHeader represents the desctuctor for a MyTHeader class
MyTHeader::~MyTHeader() {
    cout << "Destructor for Client MyTHeader class" << endl;
}

// MyT_send is called in sendto to send a segment 
void MyTHeader::MyT_send() {
    cout << "MyT_send() method for Client MyTHeader class" << endl;
}