#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    const char *str = "Idle Brain is devil's workshop"; 
    int l = strlen(str);
    char *ptr;
    ptr = new char[l + 1]; 
    strcpy(ptr, str); 
    cout << ptr << endl;
    delete[] ptr; 
    return 0;
}