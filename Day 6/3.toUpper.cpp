#include <iostream>
using namespace std;

int main()
{
    string n;
    cout << "Enter the string:" << endl;
    cin >> n;
    string p = "";
    for (char i : n)
    {
        if (i >= 'a' && i <= 'z')
            p += (i - 32);
    }
    cout << p;
    return 0;
}