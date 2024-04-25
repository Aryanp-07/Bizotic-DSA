#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int current = 1000;
    int mini = 1000;
    int n, x;
    vector<int> arr;

    cout << "Enter the size of array" << endl;
    cin >> n;
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (current > 0)
            current = arr[i];
        else
            current += arr[i];

        mini = min(mini, current);
        cout << "mini " << mini << " current " << current << endl;
    }

    cout << "The minimum sum is " << mini << endl;

    return 0;
}
// 3 -4 2 -3 -1 7 -5