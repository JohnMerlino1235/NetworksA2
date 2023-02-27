#ifndef mysocket_h
#define mysocket_h

#define SERVER_ADDRESS 32
#define LOCAL_PORT_ADDRESS 33

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
        SkBuf(char* m, short fA);
        ~SkBuf();
        int get_message_length();
        short get_local_port();
        char* get_head();
        int get_head_length();
        void add_THeader(char* tSegment);
        void add_LHeader(char* lSegment);
}; 

void send_to(char* message);

#endif
