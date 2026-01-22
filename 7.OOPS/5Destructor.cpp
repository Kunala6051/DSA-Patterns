#include <iostream>
#include <string> 

using namespace std;

// Destructor:
    // This is called when an object goes out of scope or is deleted
    // It is used to release resources that the object may have acquired

    // This is really important for memory management in C++ when there is dynamic memory allocation involved
    // If you allocate memory using 'new', you should release it using 'delete' in the destructor
    // This helps to prevent memory leaks

class MyClass {
    int data; // Example member variable
    int *ptr;
public:
    MyClass(int d, int val) {
        ptr = new int;  // Dynamic memory allocation
        *ptr = val;
        data = d;
        cout << "Constructor called!" << endl;
    }

    ~MyClass() { // Static memory will automatically be released
        // But we have to manually free the memory to which ptr is pointing(in heap)
        delete ptr;  // Release dynamically allocated memory
        cout << "Destructor called!" << endl;
    }

    void display(){
        cout << "data: " << data << endl;
        cout << "*ptr: " << *ptr << endl;
    }
};

int main() {
    MyClass obj(5, 10);  // Constructor is called
    cout << "Main ongoing" << endl;
    obj.display();

    return 0;     // Destructor is called
}