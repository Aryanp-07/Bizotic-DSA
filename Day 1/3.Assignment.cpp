#include <iostream>

using namespace std;

int jumps = 0;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int arr[20];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int reach = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        reach = max(reach, i + arr[i]);
        cout << "Last: " << last << " Value: " << arr[i] << endl;
        if (i == last)
        {
            last = reach;
            jumps++;
        }
    }

    if (n == 1)
        jumps = 0;

    cout << "Solution = " << jumps << endl;
}

//* ashank2507david@gmail.com