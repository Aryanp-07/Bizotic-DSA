#include <iostream>
using namespace std;

void function()
{
    int x = 10;        //* auto storage class
    static int y = 10; //* static storage class
    extern int z;      //* extern storage class

    cout << x << " " << y << " " << z << endl;
    x++, y++, z++;
}

int main()
{
    function(); //? 10 10 10
    function(); //? 10 11 11
    function(); //? 10 12 12
    return 0;
}

int z = 10; //* extern has program scope