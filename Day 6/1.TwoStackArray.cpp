#include <iostream>
using namespace std;
#define N 20
//* program to implement two stacks as a single array
class Stack
{
    int top1;
    int top2;
    int *arr;

public:
    Stack() : arr(new int[N]), top1(-1), top2(N) {}

    void push1(int data)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack 1 overflow" << endl;
            return;
        }
        arr[++top1] = data;
    }

    void push2(int data)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack 2 overflow" << endl;
            return;
        }
        arr[--top2] = data;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top1--] << endl;
    }

    void pop2()
    {
        if (top2 == N)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top2++] << endl;
    }

    // void display() //* not allowed in actual implementation of stack
    // {
    //     for (int i = 0; i <= top1; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    //     for (int i = N / 2; i <= top2; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }
};

int main()
{
    Stack st;
    // st.push1(5);
    // st.push1(3);
    // st.push2(7);
    // st.pop1();
    // st.pop2();
    // st.pop2();

    // st.push1(1);
    // st.push2(2);
    // st.pop1();
    // st.push1(3);
    // st.pop1();
    // st.pop1();
    return 0;
}