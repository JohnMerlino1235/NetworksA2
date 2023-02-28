#include "mydriver.h"
#include "mysocket.h"
#include "mylink.h"
#include "mytransport.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "mydriver.h"
#include "mysocket.h"
#include "mylink.h"
#include "mytransport.h"

using namespace std;

/* In the server application, include the following lines at the beginning of the 
code to delete any content of the file before the server program execution:
 *  ofstream outfile("/root/.../client_to_server.txt", ofstream::trunc);
 *  outfile.close();
 */

void driver_rcv(SkBuf* buffer) {
	cout << "mydriver rcvFrom buffer: " << buffer << endl;
    ifstream infile(PATH);
    if (!infile) {
        cerr << "Error opening the file for reading\n";
	exit(0);
    }
    static streampos posFile;
    infile.seekg(posFile);
    string st_recv;
    bool wait=true;

    while (wait) {
        if (getline(infile,st_recv)) {
	    memcpy(buffer->getHead(), st_recv.c_str(), st_recv.length());
	    posFile = infile.tellg();
	    wait=false;
	}
	else {
	    infile.close();
	    infile.open(PATH);
	    if (!infile) {
	        cerr << "Error opening the file for reading\n";
		exit(0);
	    }
	    infile.seekg(posFile);
	}
    }
	cout << "file closed" << endl;
    infile.close();
}