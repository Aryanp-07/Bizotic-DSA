#include <iostream>
using namespace std;
#define N 20

class Stack
{
    int *arr;
    int top;

public:
    Stack() : arr(new int[N]), top(-1) {}

    ~Stack() //* destructor
    {
        delete[] arr;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == N - 1; }

    void display() //* not allowed in actual implementation of stack
    {
        for (int i = top; i > -1; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    cout << "isFull = " << st.isFull() << endl;
    cout << "TOP = " << st.peek() << endl;
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.pop();
    cout << "isEmpty = " << st.isEmpty() << endl;

    return 0;
}