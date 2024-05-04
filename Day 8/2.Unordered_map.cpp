#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> hashMap; //* unordered_map is a set (unique elements) of pairs (pair<int,string>)
    hashMap[1] = "one";
    hashMap[2] = "two";
    hashMap[3] = "three";

    cout << hashMap.at(2) << endl; //* returns the value of the key passed

    if (hashMap.find(4) == hashMap.end())
        cout << "Element not found" << endl;
    else
        cout << "Element found" << endl;

    for (auto i : hashMap)
        cout << i.first << " " << i.second << endl;

    return 0;
}