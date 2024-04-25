# Storage Classes
Storage classes are available only in C/C++.Storage classes have 4 attributes -
> Storage - Where is the variable stored?

> Scope - Where can the variable be accessed?

> Default Value - What is the initial value?

> Lifetime - How long is the variable available in the Storage?

 
Storage Classes are of four types -
* **Auto**
    
    It is the default storage class for all local variables.    
    Ex: _auto int i;_
    - Storage - `RAM`
    - Scope - `Block`
    - Default Value - `Garbage`
    - Lifetime - `Block`
  
* **Static**
    
    It is used to define static variables. Static variables cannot be reinitialized.    
    Ex: _static int i;_
    - Storage - `RAM`
    - Scope - `Block`
    - Default Value - `0`
    - Lifetime - `Program`
  
* **Extern**
    
    It is used to define variables at file scope. It cannot be initialized directly.   
    Ex: _extern int i;_
    - Storage - `RAM`
    - Scope - `Program`
    - Default Value - `0`
    - Lifetime - `Program`
  
* **Register**

    It is used to define variables in registers. It is used to store temporary variables.    
    Ex: _register int i;_
    - Storage - `Register`
    - Scope - `Block`
    - Default Value - `Garbage`
    - Lifetime - `Block`


# Pointers
### Types of Pointers
* **Typed pointers**: They are pointers that point to a specific type of data.  

    Ex - _int*, float*, double*, char*, struct*, className*_

* **Untyped pointers**: They are also known as Generic pointers. They do not have any datatype. It cannot be pointed towards any datatype unless it is typecasted.  
    
    Ex - _void*_

### Categories of Pointers

* **Wild Pointers**: When a pointer is declared but not initialized, it contains a garbage address. Hence it might point to any memory location. This type of pointer is known as Wild Pointer. 
    
    Ex: _int *ptr;_

* **NULL Pointers**: When a pointer is declared and initialized to NULL, it contains a NULL address. Hence it cannot point to any memory location. This type of pointer is known as NULL Pointer. 
    
    Ex: _int *ptr = NULL;_, _int *ptr = nullptr;_

* **Dangling Pointers**: A pointer that points towards a non-existent memory location is known as Dangling Pointer. Consider a scenario where a pointer points towards a particular memory location but the memory is then freed.In this case, the pointer will point towards nothing and is dangling.
    
    Ex: _int *ptr = (int *)0x00000000;_

* **Double Pointers**: A pointer that points towards another pointer is known as Double Pointer.
    
    Ex: _int i = 10;_ | _int *ptr1 = &i;_ | _int **ptr2 = &ptr1;_

# Variables
Variables are named memory locations. Variables are of three types -

* Normal Variables (Ex: _var_)

* Pointer Variables (Ex: _*var_)

* Reference Variables (Ex: _&var_)

# Implementing Pointer

1. Method 1

    _In main function-_
    ```
    Node* head = NULL;
    LinkedList ll;
    ll.insert(head);
    ```
    _In LinkedList class-_
    ```
    void insert(Node* head)
    {
        // head is passed by value
        head = head->next;
        // this does not affect the actual head
    }
    ```

2. Method 2

    _In main function-_
    ```
    Node* head = NULL;
    LinkedList ll;
    ll.insert(head);
    ```
    _In LinkedList class-_
    ```
    void insert(Node* &head)
    {
        // head is passed by reference
        head = head->next;
        // this changes the actual head
    }
    ```

3. Method 3

    _In main function-_
    ```
    Node* head = NULL;
    LinkedList ll;
    ll.insert(&head);
    ```
    _In LinkedList class-_
    ```
    void insert(Node** head)
    {
        // head is passed by reference
        *head = (*head)->next;
        // this changes the actual head
    }
    ```