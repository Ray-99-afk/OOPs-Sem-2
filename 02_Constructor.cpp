// Constructor & Destructor

// 1. Constructor name should be same as class name.
// 2. Constructor should not have return type, not even void.
// 3. Constructor is automatically called when object is created.

#include <iostream> // 1. Added Library
using namespace std;

class Distance {
    private:
        int feet;
        float inches; 
    
    public:
        Distance() {
            feet = 0;
            inches = 0;
        }

        Distance(int f, float i) {
            feet = f;
            inches = i;
        }

        void show() {
            cout << feet << " feet " << inches << " inches" << endl;
        }
};

int main() {
    Distance d1;         
    Distance d2(10, 6.5);
    
    d1.show(); 
    d2.show(); 

    return 0;
}