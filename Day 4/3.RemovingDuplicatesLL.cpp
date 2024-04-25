#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL; //* Self referencial pointer

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
public:
    void insert_at_tail(int data, Node *&head)
    {
        //? 1. Create a new node
        Node *newNode = new Node(data);
        //? 2. Check if head in NULL
        if (head == NULL)
            //? 3a. If head is NULL, set newNode as head
            head = newNode;
        else
        {
            //? 3b1. Create copy of head pointer for traversal
            Node *temp = head;
            //? 3b2. Traverse to the end of the LL
            while (temp->next != NULL)
                temp = temp->next;
            //? 3b3. Link the last node to newNode
            temp->next = newNode;
        }
    }

    void remove_duplicates(Node *head)
    {
        unordered_set<int> set;
        if (head == NULL || head->next == NULL)
            return;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (set.find(temp->data) == set.end())
                set.insert(temp->data);

            if (set.find(temp->next->data) != set.end())
                temp->next = temp->next->next;

            if (temp->next != NULL && set.find(temp->next->data) == set.end())
                temp = temp->next;
        }
    }

    void display(Node *head) //* head is passed by value
    {
        //* dont need to create a copy of head as head is not modified outside the scope
        while (head != NULL)
        {
            cout << head->data << "-->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    LinkedList ll;
    int n;
    cout << "Enter the size of linked list:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        ll.insert_at_tail(data, head);
    }
    ll.display(head);
    ll.remove_duplicates(head);
    ll.display(head);
}