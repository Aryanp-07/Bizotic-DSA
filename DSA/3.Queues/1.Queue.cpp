#include <iostream>
using namespace std;
#define N 20
class Queue
{
    int front;
    int back;
    int *arr;

public:
    Queue() : front(-1), back(-1), arr(new int[N]) {}

    void enqueue(int val)
    {
        if (back == N - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++back] = val;
        if (front == -1)
            front++;
    }

    void dequeue()
    {
        if (front == -1 || front > back)
            cout << "Queue Underflow" << endl;
        else if (front == back)
            front = back = -1;
        else
            front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (front == -1 || front > back)
        {
            cout << "Empty queue" << endl;
            return;
        }
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout << "Peek: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    return 0;
}