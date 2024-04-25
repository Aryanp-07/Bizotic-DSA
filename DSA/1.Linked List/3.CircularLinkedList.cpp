#include <iostream>
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
    void insert_at_head(int data, Node *&head, Node *&tail) //* head is passed by reference
    {
        //? 1. Create a new node
        Node *newNode = new Node(data);
        //? 2. Link the new node to the head
        newNode->next = head;
        //? 3. Set newNode as head
        head = newNode;
        if (tail == NULL)
            tail = head;
        tail->next = head;
    }

    void insert_at_tail(int data, Node *&head, Node *&tail)
    {
        //? 2. Check if head in NULL
        if (head == NULL)
            //? 3a. If head is NULL, set newNode as head
            insert_at_head(data, head, tail);
        else
        {
            Node *newNode = new Node(data);
            //? 3b1. Create copy of head pointer for traversal
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void insert_at_pos(int data, Node *&head, Node *&tail, int pos)
    {
        //? 1. Create a new node
        if (pos < 0 || pos > length(head))
        {
            cout << "Position out of range" << endl;
            return;
        }
        //? 2. Check if pos is 0
        if (pos == 0)
            insert_at_head(data, head, tail);
        else if (pos == length(head))
            insert_at_tail(data, head, tail);
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            while (pos != 1)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void delete_at_head(Node *&head, Node *&tail)
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void delete_at_tail(Node *&head, Node *&tail)
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *del = tail;
        tail = temp;
        tail->next = head;
        delete del;
    }

    void delete_at_pos(Node *&head, Node *&tail, int pos)
    {
        if (pos < 0 || pos > length(head))
        {
            cout << "Position out of range" << endl;
            return;
        }
        if (pos == 0)
            delete_at_head(head, tail);
        else if (pos == length(head))
            delete_at_tail(head, tail);
        else
        {
            Node *temp = head;
            while (pos != 1)
            {
                temp = temp->next;
                pos--;
            }
            Node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    int length(Node *head)
    {
        if (head == NULL)
            return 0;
        Node *temp = head;
        head = head->next;
        int count = 1;
        while (head != temp)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    void display(Node *head) //* head is passed by value
    {
        Node *temp = head;
        cout << head->data << "-->";
        head = head->next;
        while (head != temp)
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
    Node *tail = NULL;
    LinkedList ll;
    ll.delete_at_head(head, tail);   //* error
    ll.delete_at_tail(head, tail);   //* error
    ll.delete_at_pos(head, tail, 3); //* error
    ll.insert_at_head(20, head, tail);
    ll.insert_at_head(10, head, tail);
    ll.insert_at_tail(30, head, tail);
    ll.insert_at_pos(0, head, tail, 0);
    ll.insert_at_pos(40, head, tail, 4);
    ll.insert_at_pos(15, head, tail, 2);
    ll.delete_at_head(head, tail);
    ll.delete_at_tail(head, tail);
    ll.delete_at_pos(head, tail, 1);
    ll.delete_at_pos(head, tail, 0);
    ll.delete_at_pos(head, tail, 2);
    ll.display(head);
}