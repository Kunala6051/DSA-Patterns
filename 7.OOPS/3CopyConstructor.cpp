#include <iostream>
#include <string> 

using namespace std;



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

    
    Teacher(const Teacher& orgnlObj) { // This is a CUSTOM Copy Constructor
        cout << " I am a CUSTOM Copy Constructor" << endl;

        this->name = orgnlObj.name;
        this->dept = orgnlObj.dept;
        this->subject = orgnlObj.subject;
        this->salary = orgnlObj.salary;
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};


int main(){
    Teacher t1("John Doe", "Mathematics", "Algebra", 50000);
    Teacher t2(t1);

    t2.getInfo(); // Copy Constructor called, t2 is a copy of t1

    // If we do not make this custom constructor
    // The default copy constructor will be used, which performs a shallow copy.
    // This means that if we had any dynamic memory allocation, it could lead to issues.
    // In our case, since we are not using any dynamic memory, we are safe.

    t1.name = "Jane Smith"; // Changing t1's name to see if it affects t2
    cout << "After changing t1's name:" << endl;
    t2.getInfo(); // t2's name should remain "John Doe" if copy constructor worked correctly
    
    return 0;
}