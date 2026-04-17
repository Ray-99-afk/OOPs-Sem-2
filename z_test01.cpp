#include <iostream>
using namespace std;

class Car{
    public:
    string brand;
    int seats;
    float price;

Car(string b , int s , float p){
    brand = b;
    seats = s;
    price = p;
}
};

int main()
{
    Car c1("BMW", 5, 50000);
    Car c2("Audi", 4, 60000);

    cout << "Brand:" <<"\t"<< c1.brand <<"\t"<< c2.brand << endl;
    cout << "Seats:" <<"\t"<< c1.seats <<"\t"<< c2.seats << endl;
    cout << "Price:" <<"\t"<< c1.price <<"\t"<< c2.price << endl;

    return 0;
}