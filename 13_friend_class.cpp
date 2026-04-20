#include <iostream>
using namespace std;

class A {
private:
    int numA;

public:
    A() {
        numA = 12;
    }

    class B {
    private:
        int numB;

    public:
        B() {
            numB = 1;
        }

        int add() {
            A objA;
            return objA.numA + numB; 
        }
    };
};

int main() {
    A::B objB; 
    cout << "Result: " << objB.add() << endl;
    return 0;
}