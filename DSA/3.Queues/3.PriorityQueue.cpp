#include <iostream>
#include <limits.h>
using namespace std;

struct item
{
    int value;
    int priority;
};

class PriorityQueue
{
public:
    item arr[100];
    int length = -1;

    void enqueue(int value, int priority)
    {
        arr[++length].value = value;
        arr[length].priority = priority;
    }

    int peek()
    {
        int highestPriority = INT_MIN;
        int index = -1;

        for (int i = 0; i <= length; i++)
        {
            if (highestPriority == arr[i].priority && arr[index].value < arr[i].value)
                //* if priorities are same, set the element with higher value as highest priority
                index = i;
            else if (highestPriority < arr[i].priority)
            //* if priorities are different, set the element with highest priority
            {
                highestPriority = arr[i].priority;
                index = i;
            }
        }
        return index;
    }

    void dequeue()
    {
        int index = peek();
        //* Remove highestPriority element from the array and shift elements left by 1 to fill the void
        for (int i = index; i < length; i++)
            arr[i] = arr[i + 1];
        length--;
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(14, 4);
    pq.enqueue(20, 5);
    pq.enqueue(15, 3);
    pq.enqueue(12, 5);

    for (int i = 0; i < 4; i++)
    {
        int index = pq.peek();
        cout << "Priority: " << pq.arr[index].priority << "\tValue: " << pq.arr[index].value << endl;
        pq.dequeue();
    }
    return 0;
}