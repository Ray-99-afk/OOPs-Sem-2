#include <iostream>
using namespace std;

class Distance
{
    private:
        int feet;
        float inch; 

    public:
        Distance()
        {
            feet = 0; 
            inch = 0;
        }
        Distance(int f, float i)
        {
            feet = f; 
            inch = i;
        }   

        void show()
        {
            cout << feet << "\' - " << inch << "\"" << endl;
        }
        Distance operator + (Distance d2)
        { 
            int f = feet + d2.feet;
            float i = inch + d2.inch;
            if (i >= 12.0)
            { 
                i -= 12.0;
                f++;
            }
            return Distance(f, i);
        }
};

int main()
{ 
    Distance d1(5, 7), d2(6, 9), d3, d4; 
    d1.show(); 
    d2.show();
    d3.show();
    d4 = d1 + d2 + d3;
    d4.show();

    return 0; 
}