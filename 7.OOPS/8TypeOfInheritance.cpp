#include <iostream>
#include <string> 

using namespace std;


// 1. Single Inheritance
    // A class (derived class) inherits from another class (base class)

class Person {
public:
    string name;
    int age;
};

class Student : public Person {
public:
    int studentID;
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};


// 2. Multilevel Inheritance
    // A class is derived from another derived class

class GraduateStudent : public Student {
public:
    string thesisTopic;
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Thesis Topic: " << thesisTopic << endl;
    }
};


// 3. Hierarchical Inheritance
    // Multiple classes are derived from a single base class

class Teacher : public Person {
public:
    string subject;
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }
};


// // 4. Multiple Inheritance
//     // A class can inherit from more than one base class

// Below code for both Multiple and Hybrid Inheritance will give AMBIGUOS ERROR because
// BOTH THE CLASSES ARE INHERITING SAME PROPERTIES(name, age etc.), So compiler will not be able to decide which class's property to use

// class TeachingAssistant : public GraduateStudent, public Teacher {  // SEE CAREFULLY
// public:
//     void displayInfo() {
//         GraduateStudent::displayInfo();
//         Teacher::displayInfo();
//     }
// };


// // 5. Hybrid Inheritance
//     // A combination of two or more types of inheritance

// class HybridStudent : public Student, public Teacher {
// public:
//     void displayInfo() {
//         Student::displayInfo();
//         Teacher::displayInfo();
//     }
// };
// // This is a hybrid inheritance example as it combines features of both types of inheritance which are single and multiple inheritance.

int main() {

    // Single Inheritance

    Student student;
    student.name = "John Doe";
    student.age = 20;
    student.studentID = 12345;
    student.displayInfo();

    // Multilevel Inheritance

    GraduateStudent gradStudent;
    gradStudent.name = "Alice Smith";
    gradStudent.age = 25;
    gradStudent.studentID = 54321;
    gradStudent.thesisTopic = "AI in Healthcare";
    gradStudent.displayInfo();

    // Hierarchical Inheritance

    Teacher teacher;
    teacher.name = "Dr. Smith";
    teacher.age = 40;
    teacher.subject = "Mathematics";
    teacher.displayInfo();

    // Multiple Inheritance

    // TeachingAssistant ta;
    // ta.name = "Bob Johnson";
    // ta.age = 30;
    // ta.studentID = 67890;
    // ta.thesisTopic = "Machine Learning";
    // ta.subject = "Physics";
    // ta.displayInfo();

    // // Hybrid Inheritance

    // HybridStudent hybridStudent;
    // hybridStudent.name = "Charlie Brown";
    // hybridStudent.age = 22;
    // hybridStudent.studentID = 13579;
    // hybridStudent.subject = "Statistics";
    // hybridStudent.displayInfo();

    return 0;
}