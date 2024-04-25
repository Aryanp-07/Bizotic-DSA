#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    vector<int> arr;
    int a;
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    int start = 0, mid = 0, end = arr.size() - 1;
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[start]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
    cout << "Output" << endl;
    for (int x : arr)
    {
        cout << x << " ";
    }
}