#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr0 = &a;
    int *ptr1 = NULL;    //* null pointer
    int *ptr2 = nullptr; //* null pointer

    cout << a << endl;
    cout << &a << endl;
    cout << ptr0 << endl;
    cout << *ptr0 << endl;

    //* Double pointers
    int i = 50;
    int *ptr = &i;
    int **dptr = &ptr;
    int ***ddptr = &dptr;
    int ****dddptr = &ddptr;
    cout << ****dddptr << endl;
}