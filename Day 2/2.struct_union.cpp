#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
     string name;
     int usn;
} s1, s2;

union Employee
{
     char name[10];
     int empID;
} e1, e2;

int main()
{
     s1.name = "Aryan";
     s1.usn = 14;

     s2.name = "Someone";
     s2.usn = 123;

     cout << "S1  "
          << "Name: " << s1.name << " USN: " << s1.usn << endl;
     cout << "S2  "
          << "Name: " << s2.name << " USN: " << s2.usn << endl;

     strcpy(e1.name, "Aryan");
     strcpy(e2.name, "Someone");
     e1.empID = 14;  //* empID overwrites memory that was used to store name
     e2.empID = 123; //* empID overwrites memory that was used to store name

     cout << "E1  "
          << "Name: " << e1.name << " USN: " << e1.empID << endl;
     cout << "E2  "
          << "Name: " << e2.name << " USN: " << e2.empID << endl;
}
