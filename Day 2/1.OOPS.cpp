#include <iostream>
using namespace std;

class Hello //* Class names start from capital letter always
{
    int a;         //* private attribute
    void printHi() //* default access specifier is private
    {
        cout << "HI" << endl;
    }

public:    //* access specifier of all methods under it. Anything that ends with a colon is a "Label"
    int b; //* public attribute
    void printHello()
    {
        cout << "Hello" << endl;
    }

    static void printBye()
    {
        cout << "Bye" << endl;
    }

}; //* Class always ends with a semicolon

class Car //* class with a constructor
{
public:
    string brandName;
    int speed;

    //* Constructors are of two types - Default (Non-parameterized), Parameterized
    //* Default constructor is created when it is not explicitly written (Ex: class Hello)
    //* Parameterized constructor is when it explicitly written (Ex: class Car)
    Car(string brandName, int speed) //* constructor has the same name as class and must always be public
    {
        //* initialization of instance variables
        this->brandName = brandName;
        this->speed = speed;
    }

    void print()
    {
        cout << "Brand: " << brandName << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Demo //* to show working of default constructor
{
public:
    Demo() //* Default or non-parameterized constructor
    {
        cout << "Object of Demo created" << endl;
    }

    ~Demo() //* Destructor (explicitly written)
    {
        cout << "Object of Demo destroyed" << endl;
    }
};

int main() //* Main function can be written outside the class unlike Java
{
    Hello().printHello(); //* calling non-static methods without creating object
    Hello::printBye();    //* static methods can be called using scope resolution operator without creating an object
    Hello obj;            //* object creation
    obj.printHello();     //* calling non-static method using object

    Car c1("Ferrari", 250); //* object creation of class with constructor
    Car c2("Audi", 200);
    c1.print();
    c2.print();

    Demo dem; //* prints the text written in default constructor
}