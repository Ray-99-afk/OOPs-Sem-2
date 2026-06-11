# C++ Object-Oriented Programming (OOP) Study Roadmap

This roadmap is tailored to the files and topics covered in your current university session.

## Module 1: C++ Refresher & Core Mechanics 
**Estimated Time:** 1-2 Days
**Reference Files:** `01.cpp`, `11_function_new.cpp`

*   **Syntax & Structure:** Understand the basic skeleton of a C++ program (`#include`, `main()`, namespaces).
*   **Data Types & Variables:** `int`, `float`, `double`, `char`, `bool`.
*   **Functions:** 
    *   Defining and calling functions.
    *   Return types and void functions.
    *   **Crucial:** Understand Passing by Value vs. Passing by Reference (`&`).
*   **Function Overloading:** Writing multiple functions with the same name but different arguments.

## Module 2: The Core of OOP (Classes & Objects)
**Estimated Time:** 2-3 Days
**Reference Files:** `02_Constructor.cpp`, `04_English_Distnce.cpp`

*   **Classes vs. Objects:** A class is a blueprint; an object is the actual house.
*   **Access Specifiers:** Understand what `public`, `private`, and `protected` mean. (Default in C++ is private).
*   **Constructors:** Special functions used to initialize objects.
    *   Default Constructor (no arguments).
    *   Parameterized Constructor (takes arguments).
    *   Copy Constructor (creates a new object as a copy of an existing one).
*   **Destructors:** Used for memory cleanup `~ClassName()`.
*   **The `this` Keyword:** Understanding how an object refers to itself implicitly.
///ytdjghft
## Module 3: Advanced Class Features & Interactions
**Estimated Time:** 3 Days
**Reference Files:** `05_multiply.cpp`, `10_convert_string_function.cpp`

*   **Friend Functions:** Functions that are not members of a class but are granted access to its private/protected members.
*   **Operator Overloading:** Teaching C++ how to use `+`, `-`, `*`, `==` with your own custom objects (e.g., adding two `Distance` objects together).
*   **Type Conversion:** 
    *   Basic to basic (`int` to `float`).
    *   Basic to Class (using constructors).
    *   Class to Basic (using casting operators).
    *   Class to Class.

## Module 4: Inheritance (Reusability)
**Estimated Time:** 3 Days
**Reference Files:** `06_Ineritance.cpp`, `08_Type_of_Inheritance.cpp`

*   **What is Inheritance?:** Base (Parent) classes and Derived (Child) classes.
*   **Modes of Inheritance:** How public, private, and protected changes when inherited.
*   **Types of Inheritance:**
    *   Single Inheritance.
    *   Multilevel Inheritance.
    *   Multiple Inheritance (A child with two parents).
    *   Hierarchical Inheritance.
    *   Hybrid Inheritance.
*   **The Diamond Problem & Virtual Inheritance:** Solving ambiguity when inheriting from multiple classes that share a common base.

## Module 5: Polymorphism & Pointers (The Tricky Part)
**Estimated Time:** 4 Days
*(Not explicitly in your filenames, but always follows Inheritance)*

*   **Pointers:** Variables that store memory addresses. Essential for dynamic memory allocation (`new` and `delete`).
*   **Compile-time vs. Run-time Polymorphism.**
*   **Virtual Functions:** Allowing derived classes to override methods of base classes properly.
*   **Abstract Classes & Pure Virtual Functions:** Classes designed *only* to be inherited from, not instantiated directly.

## Module 6: Data Structures in C++
**Estimated Time:** 3 Days
**Reference Files:** `07_Stack.cpp`

*   **Arrays & Pointers:** How they relate.
*   **The Stack:** 
    *   LIFO structure.
    *   Implementing `push()`, `pop()`, `isEmpty()`, and `isFull()`.
*   *(Optional / Upcoming):* Queues (FIFO) and Linked Lists.

## Module 7: File Handling
**Estimated Time:** 2 Days
**Reference Files:** `File_Handeling.cpp`, `data.bin`

*   **File Streams:** `<fstream>`, `ifstream` (read), `ofstream` (write), `fstream` (both).
*   **Text Files:** Writing basic strings and data lines.
*   **Binary Files:** Writing entire objects directly to disk using `data.bin`.
    *   Using `read()` and `write()` functions with `ios::binary`.
    *   Opening modes (`ios::in`, `ios::out`, `ios::app`).

## Final Project / Practice
**Reference Files:** `How to make project` folder

*   Bring it all together: Build a console application that uses **Classes**, stores data using **File Handling**, and utilizes **Inheritance**.
*   *Example Ideas:* A student management system, a library book tracker, or a basic RPG game character creator.
