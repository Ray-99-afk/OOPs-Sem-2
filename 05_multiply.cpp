#include <iostream>
using namespace std;

class Distance
{
    private:
        int feet;
        float inch; 

    public:
        Distance()
        { feet = 0; inch = 0; }

        Distance(int f, float i)
        { feet = f; inch = i; }   

        void show()
        { cout << feet << "\' - " << inch << "\"" << endl; }
        Distance operator + (Distance d2)
        { 
            int f = feet + d2.feet;
            float i = inch + d2.inch;
            while (i >= 12)
            { 
                i -= 12;
                f++;
            }
            return Distance(f, i);
        }
        Distance operator * (int scalar)
        {
            int f = feet * scalar;
            float i = inch * scalar;
            while (i >= 12)
            {
                i -= 12;
                f++;
            }
            return Distance(f, i);
        }
};

int main()
{ 
    Distance d1(5, 7);
    Distance d2;
    d1.show();
    d2 = d1 * 3; 
    d2.show();

    return 0; 
}