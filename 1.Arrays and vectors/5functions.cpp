#include <iostream>
using namespace std;

// Functions (in c++) are stored in the memory in STACK.

int minOfTwo(int a, int b){   // int here is returntype of the function
                              // if function doesn't return anything you can use void in place of int.
    if (a<b){
        cout << a << endl;
        return a;
    } else {
        cout << b << endl;
        return b;
    }
}
int sumOfn(int n){
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=i;
    }
    cout << sum << endl;
    return sum;
}
int factorialN(int n){
    int fact=1;
    for (int i=1; i<=n; i++){
        fact*=i;
    }
    return fact;
}

int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        int a =n%10;
        sum+=a;
        n=n/10;
    }
    return sum;
}

int isPrime(int n){
    bool prime = true;
    for (int i=2; i<n; i++){
        if(n%i==0){
            prime=false;
        }
    }
    return prime;
}

// still needs to be updated 
int primeFromN(int n){

    for (int i=3; i<=n; i++){
        bool prime = true;
        for (int j=2; j<i;j++){
            if(i%j==0){
            prime=false;
            }
        
        }
        if(prime){
            cout << i << " ";
        }
    }
    
}

int ans=0;
int power=1;
int decimalToBinary(int n){
    while(n>0){
        int a=n%2;
        n=n/2;
        a=a*power;
        ans=ans+a;
        power=power*10;
    }
    return ans;
}

int ans2=0;
int power2=1;
int binaryToDecimal(int n){
    while(n>0){
        int a=n%10;
        n=n/10;
        a=a*power2;
        ans2+=a;
        power2*=2;
    }
    return ans2;

}

int main() {
    minOfTwo(10,5);
    sumOfn(10);
    int val = sumOfn(10); // will assign the returned value of the function to variable
    cout << "value = " << val << endl;
    int value2 = factorialN(5);
    cout << "value2 = " << value2 << endl;
    cout << sumOfDigits(123) << endl;

    // Finding nCr (binomial coffecient) by using already defind factorial function

    // int n;
    // cout << "Enter n:";
    // cin >> n;
    // int r;
    // cout << "Enter r:";
    // cin >> r;
    // int factn = factorialN(n);
    // int factr = factorialN(r);
    // int d = n-r;
    // int factnr = factorialN(d);
    // int denominator = factr*factnr;
    // cout << "nCr value: " << (factn/denominator) << endl;

    cout << isPrime(9) << endl;
    cout << primeFromN(10) << endl;
    cout << decimalToBinary(20) << endl;
    cout << binaryToDecimal(1111) << endl;

    return 0;
}

// HOMEWORK PENDING