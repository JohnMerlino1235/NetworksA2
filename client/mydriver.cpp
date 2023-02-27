#include "mydriver.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

/* tx path: this function writes in the file the frame transmitted.
 * Include the corresponding return type and parameters
 * Fill the function with your code
 */
void driver_send(SkBuf* buffer){
    ofstream outfile("/Users/johnmerlino/Documents/Networks/server/client_to_server.txt", ofstream::app);
    if (!outfile)
    {
       cerr << "Error opening file";
       exit(0);
    }

    /* write the content of the frame in the file
     * new line, so the next frame is written in the next line
     */
    cout << "buffer->get_head()" << buffer->get_head() << endl;
    cout << "buffer->get_head_length" << buffer->get_head_length() << endl;
    outfile.write(buffer->get_head(), buffer->get_head_length());
    outfile << endl;
    outfile.close();
}
