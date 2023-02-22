#include "mylink.h"

// MyLHeader is the constructor for the MyLHeader class
MyLHeader::MyLHeader() {
    cout << "MyLHeader server constructor" << endl;
}  

// ~MyLHeader is the destructor for the MyLHeader class
MyLHeader::~MyLHeader() {
    cout << "MyLHeader server destructor" << endl;
}

// MyL_rvc is called in MyT_rcv when ready to receive a fragment. 
void MyLHeader::MyL_rcv() {

}