#include <iostream>
using namespace std;

class student
{
public:
    string name;
    int roll;
    float cgpa ;

    student(string s , int r , float c){
        name = s;
        roll = r;
        cgpa = c;
    }
};

int main()
{
    student s1("Aryan", 187, 9.1);
    student s2("Rohan", 188, 8.5);
    // s1.name = "Aryan";
    // s1.roll = 187;
    // s1.cgpa = 9.1;

    // student s2;
    // s2.name = "Rohan";
    // s2.roll = 188;
    // s2.cgpa = 8.5;

    cout << "Name:" <<"\t"<< s1.name <<"\t"<< s2.name << endl;
    cout << "Roll:" <<"\t"<< s1.roll <<"\t"<< s2.roll << endl;
    cout << "CGPA:" <<"\t"<< s1.cgpa <<"\t"<< s2.cgpa << endl;
 
    return 0;
}



