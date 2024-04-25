#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL; //* Self referencial pointer
    Node *prev = NULL;

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
public:
    void insert_at_head(int data, Node *&head) //* head is passed by reference
    {
        //? 1. Create a new node
        Node *newNode = new Node(data);
        //? 2. Link the new node to the head
        if (head != NULL)
            head->prev = newNode;
        newNode->next = head;
        //? 3. Set newNode as head
        head = newNode;
    }

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
            newNode->prev = temp;
            temp->next = newNode;
        }
    }

    void insert_at_pos(int data, Node *&head, int pos)
    {
        //? 1. Create a new node
        if (pos < 0 || pos > length(head))
        {
            cout << "Position out of range" << endl;
            return;
        }
        //? 2. Check if pos is 0
        if (pos == 0)
            insert_at_head(data, head);
        else if (pos == length(head))
            insert_at_tail(data, head);
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            while (pos != 1)
            {
                temp = temp->next;
                pos--;
            }
            temp->next->prev = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void delete_at_head(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void delete_at_tail(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = NULL;
        delete del;
    }

    void delete_at_pos(Node *&head, int pos)
    {
        if (pos < 0 || pos > length(head))
        {
            cout << "Position out of range" << endl;
            return;
        }
        if (pos == 0)
            delete_at_head(head);
        else if (pos == length(head))
            delete_at_tail(head);
        else
        {
            Node *left = head;
            Node *right = head;
            while (pos != 1)
            {
                left = left->next;
                right = right->next;
                pos--;
            }
            right = right->next; //* move to current node
            left->next = right->next;
            right->next->prev = left;
            delete right;
        }
    }

    void deleteByVal(Node *&head, int val)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Empty linked list" << endl;
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp == head)
            head = head->next;
        delete temp;
    }

    int length(Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    void display(Node *head) //* head is passed by value
    {
        //* dont need to create a copy of head as head is not modified outside the scope
        cout << "Forward" << endl;
        while (head->next != NULL)
        {
            cout << head->data << "-->";
            head = head->next;
        }
        cout << head->data << "-->";
        cout << "NULL" << endl;
        cout << "Backward" << endl;
        while (head->prev != NULL)
        {
            cout << head->data << "-->";
            head = head->prev;
        }
        cout << head->data << "-->";
        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    LinkedList ll;
    ll.delete_at_head(head);   //* error
    ll.delete_at_tail(head);   //* error
    ll.delete_at_pos(head, 1); //* error
    ll.insert_at_head(20, head);
    ll.insert_at_head(10, head);
    ll.insert_at_tail(30, head);
    ll.insert_at_pos(0, head, 0);
    ll.insert_at_pos(40, head, 4);
    ll.insert_at_pos(15, head, 2);
    ll.delete_at_head(head);
    ll.delete_at_tail(head);
    ll.delete_at_pos(head, 1);
    ll.delete_at_pos(head, 0);
    ll.delete_at_pos(head, 2);
    ll.display(head);
}