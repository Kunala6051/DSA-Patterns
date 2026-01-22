#include <iostream>
using namespace std;

int main () {

    // Lowercase or Uppercase

    char val;
    cout << "Enter the character: ";
    cin >> val;
    if ('a'<=val && val<='z') {   // Comparing ASCII values as characters are stored as these values, (here 'a'= 97 and 'z'= 122)
        cout << "Lowercase";      // so they even can be compared by their numerical ASCII codes such as 65 for 'A'.  
    } else {
        cout << "Uppercase";
    }
    cout << endl;


    // WHILE LOOP
    // print numbers 1 to n 

    int n;
    cout << "Enter the number: ";
    cin >> n;
    int i = 1;
    while (i <= n){
        cout << i << " ";
        i++;
    }
    cout << endl;

    // FOR LOOP
    // print odd numbers from 1 to n 

    int num;
    cout << "Enter the number: ";
    cin >> num;
    for (int i=1; i<=num; i+=2){
        cout << i << " ";
    }
    cout << endl;

    // sum of n numbers

    int num1;
    cout << "Enter the number: ";
    cin >> num1;
    int sum=0;
    for (int i=1; i<=num1; i++){
        sum+=i;
    }
    cout << "Sum of first " << num1 << " numbers = " << sum;
    cout << endl;

    // Prime or Not

    int num2;
    cout << "Enter the number: ";
    cin >> num2;
    bool isPrime = true;
    for (int i=2; i<=num2-1; i++){
         if (num2%i==0){
            isPrime = false;
         }  
    }
    if (isPrime){
        cout << "Prime";
    } else {
        cout << "Not Prime";
    }
    cout << endl;

    //  NESTED LOOPS
    
    int m;
    cout << "Enter the rows: ";
    cin >> m;
    int num3;
    cout << "Enter the columns: ";
    cin >> num3;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=num3; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
    


    return 0;
}