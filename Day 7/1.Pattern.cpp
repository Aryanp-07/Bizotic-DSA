#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value: " << endl;
    cin >> n;
    long long v1 = 0, v2 = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << v1 << " ";
            long long v3 = v1 + v2;
            v1 = v2;
            v2 = v3;
        }
        cout << endl;
    }
    return 0;
}