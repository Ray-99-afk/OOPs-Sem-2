#include <iostream>
using namespace std;

class stack{
private:
    int st[3];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int var)
    {
        st[++top] = var;
    }

    int pop()
    {
        return st[top--];
    }
};

int main()
{
    stack s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    return 0;
}