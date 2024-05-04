#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);           //? 1 2 3 4
    arr.pop_back();             //? 1 2 3
    arr.insert(arr.begin(), 0); //? 0 1 2 3
    arr.erase(arr.begin() + 1); //? 0 2 3

    //* display method 1
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    //* display method 2
    for (auto it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        cout << *it << " ";
    cout << endl;

    arr.clear(); //* remove all elements

    return 0;
}