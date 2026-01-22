#include <iostream>
#include <vector>
using namespace std;

// Pointers are variables that store the address of another variable
// They are used to access and manipulate memory directly

int changeB(int b){   // Passing by value
    b = 20; // value of b will not change in main function 
    return b;
}

int changeByRef(int & b){   // Passing by reference (Passing the address of b)  
    b = 20; // value of b will change in main function 
    return b;
}
           // OR

int changeByRef2(int* ptr){   // Passing pointer as argument and derefrencing it
    *ptr = 30; // value of value stored at pointer will change in main function 
    return *ptr;
}
int main(){
    int a = 100;
    cout << &a << endl;

    int* ptr = &a;
    cout << ptr << endl;
    cout << &ptr << endl;

    // Pointer to Pointer

    int** parentPtr = &ptr;
    cout << parentPtr << endl;

    // Derefrencing operator (*)
    // It is used to get a value stored at particular memory address. It is used as *(any memory address)

    cout << *(&a) << endl;  // value of a
    cout << *(ptr) << endl;  // value of a (ptr = address of a)
    cout << *(&ptr) << endl; // value of ptr (memory address of a) as (&ptr) denotes address of ptr
    cout << *(parentPtr) << endl;
    cout << **(parentPtr) << endl; // derefrencing it two times

    // NULL Pointer (will be used further in linked list and trees)
    // If null is not used random memory address is stored in a pointer (int* ptr;)

    int** nullPtr = NULL;
    cout << nullPtr << endl;
    // Null pointers can't be derefrenced as they don't point to any value

    // PASSING BY VALUE AND REFERENCE ( reference also called ALIASING)
    // Passing by value means passing the copy of the variable to the function
    // Passing by reference means passing the address of the variable to the function


    int b=10;
    int *ptr2 = &b;


    cout << "Before: " << b << endl;
    changeB(b);
    cout << "After: " << b << endl;
    changeByRef(b);
    cout << "After: " << b << endl;
    changeByRef2(ptr2);
    cout << "After: " << b << endl;


    // ARRAY POINTERS

    int arr[5] = {1,2,3,4,5};
    // arr is already a pointer to the first element of the array
    cout << arr << endl; // address of first element
    cout << &arr[0] << endl; // address of first element

    cout << arr[0] << endl; // value of first element
    cout << *arr << endl; // value of first element

    // Value of array pointers are not modifiable unlike normal pointers
    
    int c=20, d=10;
    int* ptr3 = &c;
    ptr3 = &d; // this is allowed

    // arr= &d; // this is not allowed as arr is a constant pointer




    // Pointer Arithmetic

    // Pointer arithmetic is the process of performing arithmetic operations on pointers

    // INCREMENT / DECREMENT 
    // Incrementing a pointer moves it to the next memory address of the same type
    // i.e like if we do ptr++ , it will add one byte to the address of ptr 
    // The size of byte is 1 byte, int is 4 bytes, char is 1 byte, float is 4 bytes, double is 8 bytes( depending on the type of pointer)
    // vice versa for decrementing

    cout << "Before Increment: " << ptr3 << endl;
    ptr3++;
    cout << "After Increment: " << ptr3 << endl;

    // check the results (last two digits of the address)
    // before incrementing it was 0x61fed8  and after incrementing it is 0x61fedc
    // d8, d9, da, db, dc
    // So it is incremented by 4 bytes (as int is 4 bytes)


    // ADDITION / SUBTRACTION
    // Adding a number to a pointer moves it to the next memory address of the same type
    // i.e like if we do ptr+2 , it will add 2*4=8 bytes to the address of ptr
    // vice versa for subtracting

    cout << "Before Addition: " << ptr3 << endl;
    ptr3 = ptr3 + 2;
    cout << "After Addition: " << ptr3 << endl;
    // check the results (last two digits of the address)   
    // before addition it was 0x61fedc  and after addition it is 0x61fee4
    // dc, dd, de, df, e0, e1, e2, e3, e4

    // Array Pointer Arithmetic
    // The name of the array is a pointer to the first element of the array
    // So we can use pointer arithmetic to access the elements of the array

    // if we add 1 to the array pointer, it will point to the next element of the array
    cout << "Before Array Pointer Arithmetic: " << *arr << endl;
    
    cout << "After Array Pointer Arithmetic: " << *(arr + 1) << endl; // element at index 1
    cout << "After Array Pointer Arithmetic: " << *(arr + 2) << endl; // element at index 2

    // Pointer Subtraction
    // Pointer subtraction is the process of subtracting two pointers to get the number of elements between them
    // It is only valid for pointers of the same type

    int *ptr4; // lets say 100
    int *ptr5= ptr4 + 2;  // 108
    cout << "Pointer Subtraction: " << ptr5 - ptr4 << endl; // 2
    // It will give the number of elements between them (2 in this case)




    return 0;
}

