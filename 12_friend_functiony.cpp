#include <iostream>
using namespace std;

class Distance {
private:
    int meter;

    friend int addFive(Distance);

public:
    Distance() {
        meter = 0;
    }

    int getMeter() {
        return meter;
    }
};

int addFive(Distance d) {
    d.meter += 5;
    return d.meter;
}

int main() {
    Distance d;

    cout << d.getMeter() << endl;
    cout << addFive(d) << endl;

    return 0;
}