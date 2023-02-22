#include <iostream>

using namespace std;

// temp declaration of BUFFER_SIZE
const int BUFFER_SIZE = 0;

class SkBuf{ 
    private: 
        char * head; //pointer to the first byte of the sent bytes  
        char * message; //pointer to the first byte of the message 
        int T_length; //Length of Transport layer header 
        int L_length; //Length of Link layer header 
        int length; //Message length 
        short lAd; //Local port 
        short fAd; //Foreign port
    
    public: 
        //Tx path: m is the message and fA is the destination port 
        SkBuf(string m, short fA){ 
            head=new char[length+T_length+L_length]; 
            message=head+T_length+L_length; 
            //initialize other class members 
            // ... 
            memcpy(message,m.c_str(),length); 
        } 
        //Rx path: 
        SkBuf(){ 
                head=new char[BUFFER_SIZE]; 
                //initialize other class members 
        // ... 
                message=head+T_length+L_length; 
            } 
        //Destructor and more methods here... 
        //... 
 }; 