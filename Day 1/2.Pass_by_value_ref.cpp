#include <iostream>

using namespace std;

void swap_call_by_val(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_call_by_ref(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap_call_by_val(a, b);
    cout << "a: " << a << " b: " << b << endl;
    swap_call_by_ref(&a, &b);
    cout << "a: " << a << " b: " << b << endl;
}
