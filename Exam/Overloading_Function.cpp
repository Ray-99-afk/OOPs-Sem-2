#include <iostream>
using namespace std;

// Version 1: Adds two integers
int add(int a, int b) {
    return a + b;
}

// Version 2: Adds three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Version 3: Adds two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    cout << "Result Verson 1 : " << add(5, 10) << endl;         // Calls Version 1
    cout << "Result Verson 2 : " << add(5, 10, 15) << endl;     // Calls Version 2
    cout << "Result Verson 3 : " << add(3.5, 2.1) << endl;      // Calls Version 3
    
    return 0;
}