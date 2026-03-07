#include <iostream>
#include <string>

using namespace std;

string toloweCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] >= 'A' && str[i] <= 'Z') {
            
            str[i] = str[i] + 32; 
        }
    }
    return str;
}

int main() {
    string myString = "ASDFGHJKL";
    cout << "UpperCase: " << myString << endl;
    
    myString = toloweCase(myString);
    cout << "Lowercase: " << myString << endl;
    
    return 0;
}