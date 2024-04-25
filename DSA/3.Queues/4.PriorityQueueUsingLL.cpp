#include <iostream>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;

    Node(int val, int priority) : data(val), priority(priority), next(nullptr) {}
};

class PriorityQueue
{

    Node *head = NULL;

public:
    void enqueue(int val, int priority)
    {
        Node *newNode = new Node(val, priority);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node *peek()
    {
        Node *temp = head;
        Node *high = NULL;
        int highestPriority = INT_MIN;
        int highestVal = INT_MIN;
        while (temp != NULL)
        {
            if (highestPriority == temp->priority && temp->data > highestVal)
            {
                highestVal = temp->data;
                high = temp;
            }
            else if (highestPriority < temp->priority)
            {
                highestPriority = temp->priority;
                highestVal = temp->data;
                high = temp;
            }
            temp = temp->next;
        }
        return high;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        Node *temp = peek();
        if (temp == head)
        {
            head = head->next;
            return;
        }
        Node *temp1 = head;
        while (temp1->next != temp)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(12, 5);
    pq.enqueue(14, 1);
    pq.enqueue(22, 2);
    pq.enqueue(15, 4);
    pq.enqueue(20, 1);
    pq.enqueue(17, 3);

    for (int i = 0; i < 6; i++)
    {
        Node *temp = pq.peek();
        cout << "Priority: " << temp->priority << "\tValue: " << temp->data << endl;
        pq.dequeue();
    }
    return 0;
}