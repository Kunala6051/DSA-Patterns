#include <iostream>
#include <string> 

using namespace std;


// SHALLOW COPY

class TeacherShallow {
  
    public:
    string name;
    double *cgpaPtr; // Pointer to hold CGPA
    // Dynamically allocating memory in heap


    TeacherShallow(string name, double cgpa) { 
        this->name = name;
        this->cgpaPtr = new double; // Allocate new memory
        *cgpaPtr = cgpa; // storing at the address  
    }

    
    TeacherShallow(const TeacherShallow &orgnlObj) { // This is a Shallow Copy Constructor

        this->name = orgnlObj.name;
        this->cgpaPtr = orgnlObj.cgpaPtr;  // This will point to the same memory location
        // So if we change the CGPA of one object, the other will also change
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl; // getting value from address
    }
};


// DEEP COPY

class TeacherDeep {

    public:
    string name;
    double *cgpaPtr;


    TeacherDeep(string name, double cgpa) {                                   
        this->name = name;                                                                  
        this->cgpaPtr = new double; // Allocate new memory                                  
        *cgpaPtr = cgpa; // storing at the address                                          
                                                                              
    }


    TeacherDeep(const TeacherDeep& orgnlObj) { // This is a Deep Copy Constructor

        this->name = orgnlObj.name;
        this->cgpaPtr = new double; // Allocate new memory
        *(this->cgpaPtr) = *(orgnlObj.cgpaPtr); // Copy the value
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl; // getting value from address
    }
};

int main(){

    // Shallow copy (Change cgpa in the original object)
    TeacherShallow t1("John Doe", 8.5);
    TeacherShallow t2(t1);

    t1.getInfo();
    *(t1.cgpaPtr) = 9.0; // changing value at the address
    t2.getInfo();



    // Deep Copy
    TeacherDeep t3("John Doe", 8.5);
    TeacherDeep t4(t3);

    t3.getInfo();
    *(t4.cgpaPtr) = 9.0; // changing value at the address
    t3.getInfo();

    
}