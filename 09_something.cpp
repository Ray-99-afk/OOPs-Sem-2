#include <iostream>
using namespace std;

int main() {
    const int D = 7;

    const char* day[D] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    for(int i = 0; i < D; i++) {
        cout << day[i] << endl;
    }
    
    return 0;
}