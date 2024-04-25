#include <iostream>
#include <string>
using namespace std;
#define N 20

class Stack
{
    char *arr;
    char top;

public:
    Stack() : arr(new char[N]), top(-1) {}

    void push(char data)
    {
        if (isFull())
            return;
        arr[++top] = data;
    }

    void pop()
    {
        if (isEmpty())
            return;
        top--;
    }

    char peek()
    {
        if (isEmpty())
            return -1;
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

    bool balancedParentheses(string s)
    {
        for (char x : s)
        {
            if (x == '(' || x == '{' || x == '[')
                push(x);
            else if (x == ')' || x == '}' || x == ']')
            {
                if (peek() == '(' && x == ')')
                    pop();
                else if (peek() == '{' && x == '}')
                    pop();
                else if (peek() == '[' && x == ']')
                    pop();
                else
                    return false;
            }
        }
        if (isEmpty())
            return true;
        return false;
    }
};

int main()
{
    Stack st;
    string input;
    cout << "Enter the string:" << endl;
    getline(cin, input);
    bool result = st.balancedParentheses(input);
    if (result)
        cout << "Balanced";
    else
        cout << "Unbalanced";
    return 0;
}