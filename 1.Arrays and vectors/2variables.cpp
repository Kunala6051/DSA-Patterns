#include <iostream>
using namespace std;

int main() {
    int age=25;
    cout << age << endl;
    cout << sizeof(age) << endl;   // each int type consists of 4 bytes {32 bits(1 byte = 8 binary bits)}
    // 25 = 11001 ( only 5 bits r used but stil 32 bits are reserved for variable age)

    char grade = 'A';
    cout << sizeof(grade) << endl;
    // char = 1 byte

    float PI = 3.14f; // compulsory to write f or F behind every floating number
    cout << sizeof(PI) << endl;
    // float = 4 bytes

    bool isSafe = false; // false -> 0
    bool isAdult = true; // true -> 1
    cout << isSafe << endl;
    cout << sizeof(isAdult) << endl;
    // bool = 1 byte

    double price = 100.99; 
    cout << sizeof(price) << endl;
    // float = 8 bytes


    // TYPE CONVERSION (Converting smaller size type to bigger one (Easy)) [IMPLICIT]
    // example -> char to int, float to double
    int gradeInt = grade;
    cout << gradeInt << endl; // ASCII value of 'A' = 65

    double newPI = PI;
    cout << newPI << endl;

    // TYPE Casting (Converting bigger size type to ssmaller one (Easy)) [EXPLICIT]
    // example -> double to int
    int newPrice = (int)price;
    cout << newPrice << endl; // 100.99 -> 100 (values after decimal are ignored)


    // INPUT / OUTPUT
    // int marks;
    // cout << "Enter your marks: ";
    // cin >> marks;
    // cout << "Your marks are: " << marks << endl;
    // char Grade;
    // cout << "Enter your Grade: ";
    // cin >> Grade;
    // cout << "Your Grade is: " << Grade << endl;


    // ARTHMETIC OPERATORS (+,-,*,/,%)
    int a=23, b=22;
    int sum = a + b;
    cout << sum << endl;
    cout << "sum of a and b : " << (a+b) << endl;
    cout << "division: " << (5/2) << endl;
    // if we want result in float one value has to be float or double so for that we can use type casting
    cout << "division: " << (5/(double)2) << endl;


    // RELATIONAL OPERATORS (<,>,==,<=,>=,!=)
    // Output -> 1 for true and 0 for false
    cout << (a==b) << endl;
    cout << (a<=b) << endl;
    cout << (a!=b) << endl;
    cout << (a>b) << endl;


    // LOGICAL OPERATORS 
    // OR - Denoted by || (pipe)
    // AND - Denoted by && (this symbol is called ampersand)
    // NOT - Denoted by !
    cout << !(a>b) << endl; // Not
    cout << ((a>b) || (a<=b)) << endl; // Or
    cout << ((a>b) && (a<=b)) << endl; // And


    // UNARY OPERATORS(a++,a--)
    int c=6;
    // INCREMENT
    cout << c++ << endl; // print firstly and then increment (POST INCREMENT)
    cout << ++c << endl; // increment firstly and then print (PRE INCREMENT)
    // DECREMENT
    cout << c-- << endl; // print firstly and then decrement (POST DECREMENT)
    cout << --c << endl; // increment firstly and then print (PRE DECREMENT)




    return 0;
}
