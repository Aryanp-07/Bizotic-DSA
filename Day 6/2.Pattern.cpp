#include <iostream>
using namespace std;

// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

int main()
{
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    int maxIndex = 2 * n - 2;
    for (int i = 0; i < (2 * n - 1); i++)
    {
        for (int j = 0; j < (2 * n - 1); j++)
        {
            int mini = min(min(i, j), min(maxIndex - i, maxIndex - j));
            cout << n - mini << " ";
            // if (i < n)
            // {
            //     if (j < n)
            //         cout << n - min(i, j) << " ";
            //     else
            //         cout << n - min(i, maxIndex - j) << " ";
            // }
            // else
            // {
            //     if (j < n)
            //         cout << n - min(maxIndex - i, j) << " ";
            //     else
            //         cout << n - min(maxIndex - i, maxIndex - j) << " ";
            // }
        }
        cout << endl;
    }
    return 0;
}
