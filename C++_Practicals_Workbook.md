# C++ Practicals Workbook

This workbook contains 20 practical exercises covering the fundamental and advanced concepts of C++ Object-Oriented Programming.

---

## Practical 1: Basic I/O - Rectangle Calculator

**Aim:** Write a C++ program to calculate the area and perimeter of a rectangle using basic input/output mechanisms.

**Problem Statement:** Take the length and width of a rectangle from the user and display its area and perimeter.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    float length, width, area, perimeter;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    cout << "\n--- Results ---" << endl;
    cout << "Area of the rectangle: " << area << endl;
    cout << "Perimeter of the rectangle: " << perimeter << endl;

    return 0;
} 
```

**Expected Output:**
```text
Enter the length of the rectangle: 5.5
Enter the width of the rectangle: 4.0

--- Results ---
Area of the rectangle: 22
Perimeter of the rectangle: 19
```

---

## Practical 2: Control Flow - Leap Year Checker

**Aim:** Write a C++ program that utilizes conditional statements to determine if a year is a leap year.

**Problem Statement:** Take a year from the user and use an `if-else` block to check leap year conditions.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter a year to check: ";
    cin >> year;

    if (year % 400 == 0) {
        cout << year << " is a Leap Year." << endl;
    } else if (year % 100 == 0) {
        cout << year << " is not a Leap Year." << endl;
    } else if (year % 4 == 0) {
        cout << year << " is a Leap Year." << endl;
    } else {
        cout << year << " is not a Leap Year." << endl;
    }

    return 0;
}
```

**Expected Output:**
```text
Enter a year to check: 2024
2024 is a Leap Year.
```

---

## Practical 3: Functions - Number Swapper

**Aim:** Write a C++ program to demonstrate pass-by-reference logic using functions.

**Problem Statement:** Write a function `swapNumbers` that accepts two integers by reference and swaps their values.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

void swapNumbers(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;

    cout << "Before Swapping: a = " << a << ", b = " << b << endl;
    swapNumbers(a, b);
    cout << "After Swapping : a = " << a << ", b = " << b << endl;

    return 0;
}
```

**Expected Output:**
```text
Before Swapping: a = 10, b = 20
After Swapping : a = 20, b = 10
```

---

## Practical 4: Overloading - Shape Area Overloading

**Aim:** Implement Function Overloading in C++ to find the area of different shapes.

**Problem Statement:** Create three variations of an `area()` function to calculate the area of a circle, rectangle, and triangle.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

// Area of a Circle
float area(float radius) {
    return 3.14159 * radius * radius;
}

// Area of a Rectangle
float area(float length, float width) {
    return length * width;
}

// Area of a Triangle (Base, Height, and a dummy char to differentiate signature)
float area(float base, float height, char type) {
    return 0.5 * base * height;
}

int main() {
    cout << "Area of Circle (radius 5.0): " << area(5.0f) << endl;
    cout << "Area of Rectangle (5.0, 4.0): " << area(5.0f, 4.0f) << endl;
    cout << "Area of Triangle (base 6.0, height 4.0): " << area(6.0f, 4.0f, 't') << endl;
    return 0;
}
```

**Expected Output:**
```text
Area of Circle (radius 5.0): 78.5397
Area of Rectangle (5.0, 4.0): 20
Area of Triangle (base 6.0, height 4.0): 12
```

---

## Practical 5: Classes & Objects - Student Record System

**Aim:** Create a basic class structure in C++ containing data members and member functions.

**Problem Statement:** Define a `Student` class with attributes (name, roll_no, marks) and implement functions to input and display the record.

**Source Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll_no;
    float marks;

public:
    void getDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayDetails() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << "\nRoll No: " << roll_no << "\nMarks: " << marks << endl;
    }
};

int main() {
    Student s1;
    s1.getDetails();
    s1.displayDetails();
    return 0;
}
```

**Expected Output:**
```text
Enter Name: Aryan
Enter Roll No: 12
Enter Marks: 88.5

--- Student Details ---
Name: Aryan
Roll No: 12
Marks: 88.5
```

---

## Practical 6: Constructors - Account Initialization

**Aim:** Understand parameterized constructors in C++ Classes.

**Problem Statement:** Create a `BankAccount` class that uses a parameterized constructor to set the initial account number and balance.

**Source Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Parameterized Constructor
    BankAccount(int acc_no, double initial_balance) {
        accountNumber = acc_no;
        balance = initial_balance;
        cout << "Account created successfully for A/C: " << accountNumber << endl;
    }

    void showBalance() {
        cout << "A/C: " << accountNumber << " | Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account1(101102, 5000.50);
    account1.showBalance();
    
    BankAccount account2(101103, 12000.75);
    account2.showBalance();
    
    return 0;
}
```

**Expected Output:**
```text
Account created successfully for A/C: 101102
A/C: 101102 | Balance: $5000.5
Account created successfully for A/C: 101103
A/C: 101103 | Balance: $12000.75
```

---

## Practical 7: Copy Constructor - Data Reproducer

**Aim:** Write a program implementing a Copy Constructor in C++.

**Problem Statement:** Create a `Point` class with x and y coordinates. Use a copy constructor to initialize a new `Point` object from an existing one.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Normal Parameterized Constructor
    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }

    // Copy Constructor
    Point(const Point &p2) {
        x = p2.x;
        y = p2.y;
        cout << "Copy constructor called!" << endl;
    }

    void display() {
        cout << "Point Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(10, 15);
    cout << "Original Point:" << endl;
    p1.display();

    Point p2 = p1; // Invokes Copy Constructor
    cout << "Copied Point:" << endl;
    p2.display();

    return 0;
}
```

**Expected Output:**
```text
Original Point:
Point Coordinates: (10, 15)
Copy constructor called!
Copied Point:
Point Coordinates: (10, 15)
```

---

## Practical 8: Destructors - Scope Identifier

**Aim:** Observe the invocation of constructors and destructors when objects go in and out of scope.

**Problem Statement:** Design a class `Tracker` that prints messages during initialization and destruction to track its scope limits.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Tracker {
private:
    int id;
public:
    Tracker(int i) {
        id = i;
        cout << "Object " << id << " created." << endl;
    }
    
    ~Tracker() {
        cout << "Object " << id << " destroyed!" << endl;
    }
};

int main() {
    cout << "Inside main function." << endl;
    Tracker t1(1);

    {
        cout << "Inside inner block." << endl;
        Tracker t2(2);
    }
    
    cout << "Back in main function." << endl;
    return 0;
}
```

**Expected Output:**
```text
Inside main function.
Object 1 created.
Inside inner block.
Object 2 created.
Object 2 destroyed!
Back in main function.
Object 1 destroyed!
```

---

## Practical 9: Friend Function - Cross-Class Mean

**Aim:** Utilize a Friend Function to access private data from two different classes.

**Problem Statement:** Create two classes (`ClassA` and `ClassB`) storing an integer. Write a friend function to both classes that calculates the mean of their corresponding values.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
private:
    int numA;
public:
    ClassA(int n) : numA(n) {}
    friend float calculateMean(ClassA, ClassB);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int n) : numB(n) {}
    friend float calculateMean(ClassA, ClassB);
};

float calculateMean(ClassA a, ClassB b) {
    return (a.numA + b.numB) / 2.0f;
}

int main() {
    ClassA objA(15);
    ClassB objB(20);

    cout << "Mean of two objects is: " << calculateMean(objA, objB) << endl;
    return 0;
}
```

**Expected Output:**
```text
Mean of two objects is: 17.5
```

---

## Practical 10: Friend Class - Secret Accessor

**Aim:** Implement a Friend Class that can manipulate private data from another class.

**Problem Statement:** Make a class `Vault` containing a private pin. Create a friend class `Hacker` that accesses and decrypts the pin.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Vault {
private:
    int secretPin;
public:
    Vault(int pin) {
        secretPin = pin;
    }
    friend class Hacker;
};

class Hacker {
public:
    void extractPin(Vault v) {
        cout << "Hacking complete! The secret pin accessed is: " << v.secretPin << endl;
    }
};

int main() {
    Vault myVault(7788);
    Hacker mrRobot;

    mrRobot.extractPin(myVault);

    return 0;
}
```

**Expected Output:**
```text
Hacking complete! The secret pin accessed is: 7788
```

---

## Practical 11: Unary Overloading - Distance Incrementor

**Aim:** Try implementing an overloaded Unary Operator (`++` operator) on a custom Class.

**Problem Statement:** Overload the `++` prefix operator in a `Distance` class to increment feet and inch values simultaneously.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    // Overloading prefix ++
    void operator++() {
        feet++;
        inches++;
        if (inches >= 12) {
            feet++;
            inches -= 12;
        }
    }

    void display() {
        cout << feet << " feet, " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 11);
    cout << "Original distance: ";
    d1.display();

    ++d1;
    cout << "After applying ++: ";
    d1.display();

    return 0;
}
```

**Expected Output:**
```text
Original distance: 5 feet, 11 inches
After applying ++: 7 feet, 0 inches
```

---

## Practical 12: Binary Overloading - Complex Addition

**Aim:** Implement Binary Operator Overloading (`+`) to concatenate or add attributes of two objects.

**Problem Statement:** Create a `Complex` number class (real and imaginary). Overload the `+` operator so we can execute `c3 = c1 + c2`.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex() { real = 0; imag = 0; }
    Complex(float r, float i) { real = r; imag = i; }

    Complex operator+(Complex c2) {
        Complex temp;
        temp.real = real + c2.real;
        temp.imag = imag + c2.imag;
        return temp;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3;

    c3 = c1 + c2; // Binary '+' invoked

    cout << "Complex Number 1: "; c1.display();
    cout << "Complex Number 2: "; c2.display();
    cout << "Sum using + operator: "; c3.display();

    return 0;
}
```

**Expected Output:**
```text
Complex Number 1: 3.5 + 2.5i
Complex Number 2: 1.5 + 4.5i
Sum using + operator: 5 + 7i
```

---

## Practical 13: Conversion - Int to Time Object

**Aim:** Convert a basic basic data type to a class Type.

**Problem Statement:** Design a constructor mapping an `int` variable (storing total minutes) directly to a `Time` class separating it into hours and minutes.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time() { hours = 0; minutes = 0; }

    // Basic to Class Conversion Constructor
    Time(int t) {
        hours = t / 60;
        minutes = t % 60;
    }

    void display() {
        cout << hours << " Hours and " << minutes << " Minutes" << endl;
    }
};

int main() {
    int duration = 135; 
    Time t1;
    
    t1 = duration; // Basic integer to Time Object conversion

    cout << "Duration in total minutes: " << duration << endl;
    cout << "Converted to Object format: ";
    t1.display();

    return 0;
}
```

**Expected Output:**
```text
Duration in total minutes: 135
Converted to Object format: 2 Hours and 15 Minutes
```

---

## Practical 14: Conversion - Distance to Float

**Aim:** Convert a User Defined Class to a Basic Data Type using a casting operator.

**Problem Statement:** Convert a `Distance` class (having meters and centimeters) entirely into a `float` number representing the total scale in meters.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Distance {
private:
    int meters;
    float centimeters;

public:
    Distance(int m, float cm) {
        meters = m;
        centimeters = cm;
    }

    // Casting operator for Class to Basic conversion
    operator float() {
        float f = meters + (centimeters / 100.0f);
        return f;
    }
};

int main() {
    Distance d1(5, 75.5); // 5 meters, 75.5 cm
    
    float totalMeters = d1; // Implicit casting via overloaded operator

    cout << "Distance Object parameters: 5 m, 75.5 cm" << endl;
    cout << "Float Representation in meters: " << totalMeters << " m" << endl;

    return 0;
}
```

**Expected Output:**
```text
Distance Object parameters: 5 m, 75.5 cm
Float Representation in meters: 5.755 m
```

---

## Practical 15: Single Inheritance - Person to Employee

**Aim:** Understand Single Inheritance concepts.

**Problem Statement:** Write a basic `Person` class (base) and derive an `Employee` class from it inheriting generic traits.

**Source Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
public:
    void setPersonParams(string n, int a) {
        name = n;
        age = a;
    }
};

// Derived Class
class Employee : public Person {
private:
    float salary;
public:
    void setEmployeeParams(string n, int a, float s) {
        setPersonParams(n, a);
        salary = s;
    }
    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp1;
    emp1.setEmployeeParams("John Doe", 32, 55000.0);
    
    cout << "Employee Details Extracted:" << endl;
    emp1.showDetails();

    return 0;
}
```

**Expected Output:**
```text
Employee Details Extracted:
Name: John Doe, Age: 32, Salary: $55000
```

---

## Practical 16: Multilevel Inheritance - Vehicle Hierarchy

**Aim:** Construct a multilevel inheritance hierarchy.

**Problem Statement:** Derive `Car` from `Vehicle` and `ElectricCar` from `Car`.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle Initialized." << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "Car Initialized." << endl;
    }
};

class ElectricCar : public Car {
public:
    ElectricCar() {
        cout << "ElectricCar Initialized." << endl;
    }
    void chargeBattery() {
        cout << "Battery charging..." << endl;
    }
};

int main() {
    cout << "Creating an Electric Car Object: " << endl;
    ElectricCar myTesla;
    myTesla.chargeBattery();
    
    return 0;
}
```

**Expected Output:**
```text
Creating an Electric Car Object: 
Vehicle Initialized.
Car Initialized.
ElectricCar Initialized.
Battery charging...
```

---

## Practical 17: Multiple Inheritance - Character Skills

**Aim:** Merge two base classes into one derived class via Multiple Inheritance.

**Problem Statement:** Build a `Fighter` class and `Mage` class. Derive a `Hybrid` character that inherits traits from both branches.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Fighter {
public:
    void meleeAttack() {
        cout << "Performing Sword Slash!" << endl;
    }
};

class Mage {
public:
    void castSpell() {
        cout << "Casting Fireball!" << endl;
    }
};

class Hybrid : public Fighter, public Mage {
public:
    void useCombo() {
        cout << "Using hybrid combo attack..." << endl;
        meleeAttack();
        castSpell();
    }
};

int main() {
    Hybrid myHero;
    
    cout << "Hero Actions:" << endl;
    myHero.meleeAttack();
    myHero.castSpell();
    
    cout << "\nSpecial Execution:" << endl;
    myHero.useCombo();

    return 0;
}
```

**Expected Output:**
```text
Hero Actions:
Performing Sword Slash!
Casting Fireball!

Special Execution:
Using hybrid combo attack...
Performing Sword Slash!
Casting Fireball!
```

---

## Practical 18: Virtual Base Class - Diamond Problem

**Aim:** Utilize virtual inheritance to mitigate naming ambiguities (Diamond Problem).

**Problem Statement:** Derive `B` and `C` from `A`. Derive `D` using multiple inheritance from `B` and `C`. Use virtual base classes to only have one instance of `A` data.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class A {
public:
    int globalID;
    A() { globalID = 100; }
};

// Virtual inheritance ensures only 1 copy of class A goes into derived classes.
class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {
public:
    void printID() {
        // Without 'virtual', globalID would be ambiguous.
        cout << "Global ID resolved to: " << globalID << endl; 
    }
};

int main() {
    D objD;
    objD.printID();
    
    return 0;
}
```

**Expected Output:**
```text
Global ID resolved to: 100
```

---

## Practical 19: Polymorphism - Virtual Drawing

**Aim:** Attain Runtime Polymorphism using Virtual Functions and Pointers.

**Problem Statement:** Use a base `Shape` class with a virtual `draw()` method, overriding it in `Circle` and `Square` classes and invoking through base pointers.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle!" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square!" << endl;
    }
};

int main() {
    Shape* shapePtr;
    Circle c;
    Square s;

    // Pointer pointing to circle
    shapePtr = &c;
    shapePtr->draw();

    // Pointer pointing to square
    shapePtr = &s;
    shapePtr->draw();

    return 0;
}
```

**Expected Output:**
```text
Drawing a Circle!
Drawing a Square!
```

---

## Practical 20: File Handling - Data Logger

**Aim:** Read and write persistent application data to a filesystem text file.

**Problem Statement:** Open an output file stream (`ofstream`), write a log message to `user_log.txt`, close it, and reopen with an input stream (`ifstream`) to read it back.

**Source Code:**
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "user_log.txt";

    // Write to file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error establishing file for writing." << endl;
        return 1;
    }
    
    outFile << "Student Practical Entry 20" << endl;
    outFile << "Status: Success" << endl;
    outFile.close();
    cout << "Data effectively written to " << filename << endl;

    // Read from file
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error finding file for reading." << endl;
        return 1;
    }

    cout << "\n--- Reading Data Back ---" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    
    return 0;
}
```

**Expected Output:**
```text
Data effectively written to user_log.txt

--- Reading Data Back ---
Student Practical Entry 20
Status: Success
```
