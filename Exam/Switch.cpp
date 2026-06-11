#include <iostream>
using namespace std;

int main() {
int x = 2;
switch(x) {
    case 1: cout << "One ";
    case 2: cout << "Two ";    // matches here
    case 3: cout << "Three ";  // falls through!
    default: cout << "Default"; // falls through!
}
return 0;
}