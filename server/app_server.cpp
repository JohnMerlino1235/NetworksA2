#include "mysocket.h"
#include <iostream>

using namespace std;

int main(void) {
    while (true) {
        char* message = rcvfrom();
        cout << "hlelo world" << endl;
        cout << "message" << message << endl;
    }

    return 0;
}
