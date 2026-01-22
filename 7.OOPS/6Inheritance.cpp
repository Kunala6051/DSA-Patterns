#include <iostream>
#include <string> 

using namespace std;

// Inheritance:
    // Inheritance allows a class to inherit properties and methods from another class
    // The class that is inherited from is called the base class (or parent class)
    // The class that inherits is called the derived class (or child class)

class Person{
    
public:
    string name;
    int age;
    Person(){
        cout << "Person constructor called!" << endl;
    }

    ~Person() {
        cout << "Person destructor called!" << endl;
    }
};

class Student : public Person {
    
public:
    int studentID;
    Student() {
        cout << "Student constructor called!" << endl;
    }

    ~Student() {
        cout << "Student destructor called!" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};
// Parent Class Constructor is always called before the Derived Class Constructor 
// when object of Derived Class is created

// But in case of destructor, Derived Class Destructor is called before the Base Class Destructor
// i.e, Memory deallocation happend for Derived Class first, then Base Class



// CASE OF PARAMETERIZED CONSTRUCTOR
class PersonPara{
    // If name and age are defined in private section then they will not be inherited by the derived class
    // If we write protected here: name and age will become protected properties of PersonPara and can be accessed in derived classes
public:  
    string name;
    int age;
    PersonPara(string n, int a){
        name = n;
        age = a;
    }
};

class StudentPara : public PersonPara {
    // If we write private here: name and student will become private properties of StudentPara
    // If we write protected here: name and student will become protected properties of StudentPara
public:
    int studentID;
    StudentPara(string n, int a, int id) : PersonPara(n, a) { // Calling base class constructor
        studentID = id;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};




int main() {
    Student s;
    s.name="Kunal Ahuja";
    s.age=20;
    s.studentID=8545;
    s.display(); 
    cout << endl;


    StudentPara sp("Kunal Ahuja", 20, 8545);
    sp.display();


    return 0;
}