#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class MaxHeap
{
    vector<int> arr;

    int parent(int i) { return (i - 1) / 2; }
    int lchild(int i) { return 2 * i + 1; }
    int rchild(int i) { return 2 * i + 2; }

    void heapify(int i)
    {
        int l = lchild(i); //* find the left child of current node
        int r = rchild(i); //* find the right child of current node
        int largest = i;
        if (l < arr.size() && arr[l] > arr[i]) //* if lchild is larger, set largest to l
            largest = l;
        if (r < arr.size() && arr[r] > arr[i]) //* if rchild is larger, set largest to r
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int key)
    {
        //* insert at the end of the heap
        arr.push_back(key);

        //* heapify the tree
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    int deleteMax()
    {
        if (arr.size() <= 0)
        {
            return INT_MIN;
        }
        int root = arr.front();
        swap(arr.front(), arr.back());
        arr.pop_back();
        heapify(0);
        return root;
    }

    void deleteKey(int i)
    {
        arr[i] = arr.back();
        arr.pop_back();
        heapify(i);
    }

    void display()
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    MaxHeap mh;
    mh.insert(5);
    mh.insert(10);
    mh.insert(20);
    mh.display();
    cout << mh.deleteMax() << endl;
    mh.display();
    mh.deleteKey(1);
    mh.display();
    return 0;
}