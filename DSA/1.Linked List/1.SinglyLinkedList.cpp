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
    void insert_at_head(int data, Node *&head) //* head is passed by reference
    {
        //? 1. Create a new node
        Node *newNode = new Node(data);
        //? 2. Link the new node to the head
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
            newNode->next = temp->next;
            temp->next = newNode;
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

    void delete_value(int data, Node *&head)
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        int pos = -1;
        Node *temp = head;
        while (temp != NULL)
        {
            pos++;
            if (temp->data == data)
            {
                delete_at_pos(head, pos);
                break;
            }
            temp = temp->next;
        }
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
    // ll.delete_at_head(head);   //* error
    // ll.delete_at_tail(head);   //* error
    // ll.delete_at_pos(head, 3); //* error
    ll.insert_at_head(10, head);
    ll.insert_at_head(10, head);
    ll.insert_at_tail(10, head);
    ll.insert_at_pos(0, head, 0);
    ll.insert_at_pos(40, head, 4);
    ll.insert_at_pos(15, head, 2);
    // ll.delete_value(10, head);
    // ll.delete_at_head(head);
    // ll.delete_at_tail(head);
    // ll.delete_at_pos(head, 1);
    // ll.delete_at_pos(head, 0);
    // ll.delete_at_pos(head, 2);
    ll.display(head);
}