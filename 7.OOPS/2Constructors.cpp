#include <iostream>
#include <string> 

using namespace std;

// Constructors: 

    // A constructor is a special member function that is automatically called when an object of a class is created.
    // Constructors don't have a return type.
    // It is used to initialize the object's properties.
    // Memory allocation for the object is done when the constructor is called.
    // Multiple constructors can be defined in a class (constructor overloading).


// Type of Constructors:

    // 1. Non-Parameterized Constructor: A constructor that doesn't take any arguments.
    // 2. Parameterized Constructor: A constructor that takes arguments to initialize an object with specific values.
    // 3. Copy Constructor: A constructor that creates a new object as a copy of an existing object.  

class Teacher {
  private:
    double salary;

    public:
    string name;
    string dept;
    string subject;

    Teacher(){ // Non-Parameterized Constructor
        cout << "Non-Parameterized Constructor called" << endl; // This constructor is called when no arguments are passed
    }

    Teacher(string n, string d, string s, double salary) { // Parameterized Constructor
        this->name = n;
        (*this).dept = d;
        this->subject = s;
        this->salary = salary;
        cout << "Parameterized Constructor called" << endl;
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

// How THIS Pointer Works

    // The 'this' pointer is an implicit pointer available in non-static member functions of a class.
    // It points to the object for which the member function is called.

    // Example of using 'this' pointer
    // void setName(string name) {
    //     this->name = name; // 'this' pointer is used to distinguish between member variable and parameter
    // }


    // Like other pointers which can be dereferenced, THIS can also be dereferenced to directly use obj 
    // It is used as (*this).propertyName





int main(){
    Teacher t1; // Non-Parameterized Constructor
    Teacher t2("John Doe", "Mathematics", "Algebra", 50000); // Parameterized Constructor

    t1.getInfo(); // No Values Set
    t2.getInfo();

    return 0;
}