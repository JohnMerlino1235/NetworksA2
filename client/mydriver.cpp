#include "mydriver.h"
using namespace std;

/* tx path: this function writes in the file the frame transmitted.
 * Include the corresponding return type and parameters
 * Fill the function with your code
 */
... driver_send(...){
    ofstream outfile("/root/.../client_to_server.txt",ofstream::app);
    if (!outfile)
    {
       cerr << "Error opening file";
      // ...;
    }
    /* write the content of the frame in the file
     * new line, so the next frame is written in the next line
     */
    outfile.write(...,...);
    outfile << endl;
    outfile.close();
}



/* rx path: this function reads from the file the frame received.
 * Include the corresponding return type and parameters
 * Fill the function with your code
 */
... driver_rcv(...){
    ifstream infile("/root/.../client_to_server.txt");
    if (!infile){
        cerr << "Error opening the file \n";
        //...;
    }
    
    /* variable posFile retains its value even after it goes out of scope (this 
line is only executed once)
     * we look for the last position in the file after the previous reception
     */
    static streampos posFile;
    infile.seekg(posFile);
    string st_recv;
    bool wait=true;
   
    while (wait){
        /* if there is a new line, i.e., something received
         * copy the line in memory
         * store the new position in the file
         */
        if(getline(infile,st_recv))
        {
            memcpy(...,st_recv.c_str(),st_revc.length());
            posFile = infile.tellg();
            wait=false;
            //...
        
        /* if end of file, no new line
         * close and open updated file in case something new is writen
         * go back to the last file position
         */
        }else{
            infile.close();
            infile.open("/root/.../client_to_server.txt");
            if (!infile){
                cerr << "Error opening file \n";
                //...;
            }
            infile.seekg(posFile);
        }
    }
    infile.close();
    //...
}