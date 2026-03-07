#include <iostream>
using namespace std;

class Distance {
    private:
        int feet;
        float inch; 

    public:
        Distance() {
            feet = 0;
            inch = 0;
        }

        Distance(int f, float i) {
            feet = f;
            inch = i;
        }


        void getData() {
            cout << "Enter Feet: ";
            cin >> feet;
            cout << "Enter Inch: ";
            cin >> inch;
        }

        void show() {
            cout << feet << "\' - " << inch << "\"" << endl;
        }

        Distance AddData(Distance d2) {
            Distance d;      
       
            d.feet = feet + d2.feet;
            d.inch = inch + d2.inch;

            if (d.inch >= 12.0) {
                d.inch = d.inch - 12.0;
                d.feet++;
            }

            return d; 
        }
};

int main() {
    Distance d1, d2, d3; 

    cout << "--- For d1 ---" << endl;
    d1.getData();
    
    cout << "--- For d2 ---" << endl;
    d2.getData();

    d3 = d1.AddData(d2); 

    cout << "\nOutput:" << endl;
    cout << "d1: "; d1.show();
    cout << "d2: "; d2.show();
    cout << "d3 (Total): "; d3.show();

    return 0;
}