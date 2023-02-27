#include "mysocket.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main(void){
    // setting up variables
    char username[20];
    char room[20];
    char type;
    int value;
    char movement;
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
        if(type == 'T' || type == 'H'){
            cin >> value;
            char message[50];
            sprintf(message, "%s %s %d %d", username, room, type, value);
            send_to(message);
        }
        // if the type is movement it takes in a char value and formats the message
        if(type == 'M') {
            cin >> movement;
            char message[50];
            sprintf(message, "%s %s %d %s", username, room, type, movement);
            send_to(message);
        }

        // asks the user if they want to keep measuring, the loop breaks and program ends if they say false
        cout << "Would you like to keep measuring? (true or false) ";
        cin >> keepMeasuring;
    }
}