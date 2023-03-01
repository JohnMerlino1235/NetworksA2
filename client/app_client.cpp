#include "mysocket.h"
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main(void){
    // setting up variables
    string username;
    string room;
    char type[1];
    int value;
    char movement[1];
    bool keepMeasuring = true;


    // prompt user for information
    cout << "Please enter a username: ";
    cin >> username;
    cout << "Please enter a room name: ";
    cin >> room;

    // keep repeating until the user is done entering measurements
    while (keepMeasuring) {
        cout << "Please enter the type of value (temperature(T), humidity(H), movement(M)): ";
        cin >> type;
        cout << "Please enter the value: ";
        // if the type is temp of humidity it takes in a number value and formats the message
        if(strcmp(type, "T") == 0 || strcmp(type, "H") == 0){
            cin >> value;
            string message = username + " " + room + " " + type + " " + to_string(value);
            // sprintf(message, "%s %s %s %d", username, room, type, value);
            send_to(message);
        }
        // if the type is movement it takes in a char value and formats the message
        if(strcmp(type, "M") == 0) {
            cin >> movement;
            // string message;
            string message = username + " " + room + " " + type + " " + movement;
            // sprintf(message, "%s %s %s %s", username, room, type, movement);
            send_to(message);
        }

        // asks the user if they want to keep measuring, the loop breaks and program ends if they say false
        cout << "Would you like to keep measuring? (1 for yes, 0 for no) ";
        cin >> keepMeasuring;
    }
}
