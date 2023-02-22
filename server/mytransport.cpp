#include "mytransport.h"

// The client myA port is 
// chosen during the runtime randomly and the server myA port=65.  

// MyTHeader represents the constructor for a MyTHeader class
MyTHeader::MyTHeader(short in_sAd, short in_len) {
    cout << "Constructor for Server MyTHeader class" << endl;
    sAd = in_sAd;
    dAd = 65;
    len = in_len;
    checksum = sAd + dAd + len;
}

// ~MyTHeader represents the desctuctor for a MyTHeader class
MyTHeader::~MyTHeader() {
    cout << "Destructor for Server MyTHeader class" << endl;
}