#include <iostream>
using namespace std;

//? Inheritance
/*
class Parent
{
public:
    void func1();
};

class Child1 : public Parent //* Child inherits Parent //* If public not written, Parent methods are private
{
public:
    void func2();
    void func3();
};

class Child2
{
public:
    void func3();
};

class Grandchild : public Child1, public Child2 //* Multiple inheritance is allowed in CPP
{
public:
    void func4();
};

int main()
{
    Parent obj1;
    obj1.func1();

    Child1 obj2;
    obj2.func1();
    obj2.func2();

    Grandchild obj3;
    obj3.func1();
    obj3.func2();

    //* to resolve the multiple inheritance issue of ambiguity
    obj3.Child1::func3();
    obj3.Child2::func3();

    obj3.func4();
}
*/

//? Polymorphism
/*
class Addition
{
public:
    int calc(int a, int b) { return a + b; };
    int calc(int a, int b, int c) { return a + b + c; }; //* Function Overloading
};

class Subtraction : public Addition
{
public:
    int calc(int a, int b) { return a - b; }; //* Function Overriding
};

int main()
{
    Addition obj1;
    Subtraction obj2;
    cout << obj1.calc(1, 2) << endl;
    cout << obj1.calc(1, 2, 3) << endl;
    cout << obj2.calc(1, 2) << endl;
    cout << obj2.Addition::calc(1,2); << endl;
}
*/

//? Abstraction
/*
class Demo
{
private:
    int a = 10, b = 20, sum = 0;

    int calc()
    {
        return a + b;
    }

public:
    int add()
    {
        sum = calc();
        return sum;
    }
};

int main()
{
    Demo obj; //* obj does not know calc() exists
    cout << obj.add() << endl;
}
*/

//? Encapsulation
/*
class Employee
{
    string name;
    int salary;

public:
        //* Getters and Setters are used to access private variables
    string getName() { return name; }
    int getSalary() { return salary; }

    void setName(string name) { this->name = name; }
    void setSalary(int salary) { this->salary = salary; }
};

int main()
{
    Employee e1;
    e1.setName("Aryan");
    e1.setSalary(2500000);
    cout << e1.getName() << " " << e1.getSalary() << endl;
}
*/
