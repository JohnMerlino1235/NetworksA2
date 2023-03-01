#include "mysocket.h"
#include <iostream>

using namespace std;

int main(void) {
    while (true) {
        string message = rcvfrom();
        cout << message << endl;
    }

    return 0;
}
