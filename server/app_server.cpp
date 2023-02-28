#include "mysocket.h"
#include <iostream>

using namespace std;

int main(void) {
    while (true) {
        char* message = rcvfrom();
        cout << message << endl;
        cout << "THIS IS THE MESSAGE" << message << endl;
    }

    return 0;
}
