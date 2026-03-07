#include <iostream>
using namespace std;

class counter {
protected:
    int count;

public:
    counter() { 
        count = 0; 
    }
    counter(int c) { 
        count = c; 
    }
    int getcount() { 
        return count; 
    }
    counter operator ++() { 
        return counter(++count); 
    }
};

class countdn : public counter {
public:
    countdn() : counter() {}
    countdn(int c) : counter(c) {}
    countdn operator --() { 
        return countdn(--count); 
    }
};

int main() { 
    countdn c1;
    cout<< c1.getcount() << endl;
    ++c1; 
    cout<< c1.getcount() << endl;
    --c1;
    cout<< c1.getcount() << endl;
    return 0;
}