#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Queue
{
public:
    void enqueue(int val, Node *&front, Node *&back)
    {
        Node *newNode = new Node(val);
        if (back == NULL)
            front = back = newNode;
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    void dequeue(Node *&front)
    {
        if (front == NULL)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    void display(Node *front)
    {
        while (front != NULL)
        {
            cout << front->data << "-->";
            front = front->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Node *front = NULL;
    Node *back = NULL;
    Queue q;
    q.enqueue(1, front, back);
    q.enqueue(2, front, back);
    q.display(front);
    q.dequeue(front);
    q.display(front);
    q.dequeue(front);
    q.display(front);
    return 0;
}