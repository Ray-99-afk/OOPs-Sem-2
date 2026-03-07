// WAP in c++ to  add english distance.

#include <iostream> 
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

        void getData() {
            cout << "\n Enter feet: ";
            cin >> feet;
            cout << "\n Enter inches: ";
            cin >> inches;
        }

        void show() {
            cout << "\n" << feet << " feet " << inches << " inches" << endl;
        }
}; 

int main() {
    Distance d1;        
    
    d1.getData(); 

    d1.show();

    return 0;
}