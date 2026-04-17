#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() 
    {
        cout << "Base : " << endl;
    }
};

class Derv1 : public Base
{
public:
    void show()
    {
        cout << "Derv1" << endl;
    }
};

class Derv2 : public Base
{
public:
    void show()
    {
        cout << "Derv2" << endl;
    }
};

int main()
{
    Derv1 d1; 
    Derv2 d2; 
    
    Base *ptr;    
    
    ptr = &d1;  
    ptr->show();   
    
    ptr = &d2;     
    ptr->show();   
    
    return 0;      
}