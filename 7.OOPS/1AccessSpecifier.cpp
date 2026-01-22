#include <iostream>
#include <string> 

using namespace std;

// Access Specifiers

// 1. Private: data and methods accessible only in class

// 2. Protected: data and methods accessible in class and derived classes

// 3. Public: data and methods accessible to everyone


class Teacher {
  private:
    double salary;

    public:
    string name;
    string dept;
    string subject;

    void setSalary(double sal) { // this method is called setter, which sets the value of a private variable indirectly
        salary = sal;
    }

    double getSalary() const { // this method is called getter, which gets the value of a private variable indirectly
        return salary;
    }

    void changeDept(string newDept) { // this method changes the department of the teacher
        dept = newDept;
    }
};

int main(){
    Teacher t1;

    t1.name = "John Doe";
    t1.setSalary(50000);
    t1.changeDept("Mathematics");

    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary: " << t1.getSalary() << endl;




    // ENCAPSULATION

    // Encapsulation is the bundling of data and methods that operate on that data within one unit, e.g., a class.
    // It restricts direct access to some of the object's components, which is a means of preventing unintended interference and misuse.

    // The Teacher class encapsulates the details of a teacher's information.
    // It hides the implementation details (like salary) and exposes only the necessary methods.
    // This ensures that the internal state of the object can only be changed in controlled ways.

    return 0;
}