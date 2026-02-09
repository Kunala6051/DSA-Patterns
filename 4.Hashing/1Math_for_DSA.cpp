#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10

using namespace std;

// Leetcode 204: COUNT PRIMES
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Approach:
// We can use the "SIEVE OF ERATOSTHENES" algorithm to find all prime numbers
// less than n. The algorithm works by iteratively marking the multiples of each prime number starting from 2.

// In the starting we will assume all numbers are prime and then we will mark the multiples of each prime number as not prime.
// Finally, we will count the number of true values in the isPrime array which will give us the count of prime numbers less than n.

int countPrimes(int n) {
        
    vector <bool> isPrime(n,true); // Initialize a vector of size n with all values set to true
    int count=0;

    for (int i=2; i<n; i++){
        if (isPrime[i]){
            count++;
            for (int j=i*2; j<n; j=j+i){ // Mark all multiples of i as not prime
                isPrime[j]=false; 
            }
        }
    }

    return count;
}

// Now, here the time complexity of this algorithm is O(log10 n) (base 10) as we divide n by 10 in each iteration to count the digits.
// if we would have divided n by 2, then the time complexity would have been O(log2 n) (base 2).
// Similarly, if we would have divided n by 3, then the time complexity would have been O(log3 n) (base 3).

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

// So, there is a shorter way to count the number of digits in a number n.

// Leetcode 1134: ARMSTRONG NUMBER
// An Armstrong number (also known as a narcissistic number) for a given number of digits
// is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
// For example, 153 is an Armstrong number because it has 3 digits and 1^3 + 5^3 + 3^3 = 153.
bool isArmstrong(int n) {
    int original = n;
    int sum1 = 0;
    int digits = countDigits(n);
    
    while (n > 0) {
        int digit = n % 10;
        sum1 += (int)(round(pow(digit, digits))); // Using round to avoid floating-point precision issues
        // The round function is used to ensure that we get an integer value when raising to a power.
        // This is because pow() returns a double, and we want to avoid any floating-point precision issues.
        // If we don't use round, we might get a value like 153.000000
        cout << pow(digit,digits) << " ";
        n /= 10;
    }
    cout << endl;
    cout << "Sum of digits raised to the power of number of digits: " << sum1 << endl;
    bool result = (sum1 == original);
    return result;
    
}

// Euclidean Algorithm for GCD
// The Euclidean algorithm is a method for computing the greatest common divisor (GCD) of two integers.
// It is based on the principle that the GCD of two numbers also divides their difference.

int gcdCalculator(int a,int b){
    if (a==0){ // If a is 0, then GCD is b as 0 is divisible by any number.
        return b;
    } else if (b==0){
        return a;
    } else if (a==b){ // If both numbers are equal, then GCD is a (or b) as they are the same number.
        return a;
    }

    if (a>b){
        return gcdCalculator(a%b,b);
    } else{
        return gcdCalculator(a,b%a);
    }
}

int lcmCalculator(int a, int b) {
    // LCM can be calculated using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    return (a / gcdCalculator(a, b)) * b; // To avoid overflow, we divide first
}

// Leetcode 7: REVERSE INTEGER
int reverse(int n) {
    int revNum = 0;

    while(n!=0){
        int a = n%10;

        // Check for overflow before multiplying by 10 and adding digit
        if (revNum > INT_MAX/10 || revNum < INT_MIN/10) {
            return 0; // handle overflow
        }

        revNum = revNum*10 + a;
        n=n/10;
    }
    
    return revNum;
    
}

// Leetcode 9: PALINDROME NUMBER
// A palindrome number is a number that remains the same when its digits are reversed.
bool isPalindrome(int x) {

    if (x<0){
        return false;
    } else{
        int rev=reverse(x);
        return x==rev;
    }
    
}


int main() {
    int n=50;
    
    int primeCount = countPrimes(n);
    cout << "Number of primes less than " << n << ": " << primeCount << endl;

    // Here is the shorter way to count the number of digits in a number n.
    int m = 12345;
    cout << "Number of digits in " << m << ": " << int(log10(m) + 1) << endl;
    // For example, log10(12345) + 1 = 5, which is the number of digits in 12345.

    // Check if a number is an Armstrong number
    int armstrongNumber = 153;
    if (isArmstrong(armstrongNumber)) {
        cout << armstrongNumber << " is an Armstrong number." << endl;
    } else {
        cout << armstrongNumber << " is not an Armstrong number." << endl;
    }

    // GCD calculation
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " is: " << gcdCalculator(a, b) << endl;

    // LCM calculation
    cout << "LCM of " << a << " and " << b << " is: " << lcmCalculator(a, b) << endl;

    // Reverse an integer
    int numberToReverse = 12345;
    cout << "Reversed number of " << numberToReverse << " is: " << reverse(numberToReverse) << endl;

    // Check if a number is a palindrome
    int palindromeNumber = 121;
    if (isPalindrome(palindromeNumber)) {
        cout << palindromeNumber << " is a palindrome number." << endl;
    } else {
        cout << palindromeNumber << " is not a palindrome number." << endl;
    }


    // MODULO AIRTHIMETICS

    // This concept is used in problems which expect a result that is too large to fit in standard data types.
    // For example the time complexity of a problem of next permutation of a string is O(n!).
    // If we have a string of length 50, then the number of permutations will be 50! which is a very large number.
    // So, we can use modulo arithmetic to keep the result within a manageable range.

    // The modulo operator (%) is used to find the remainder of a division operation.
    // For example, 10 % 3 = 1, because when 10 is divided by 3, the remainder is 1.

    // n%x = [0, x-1]
    // The result of n % x will always be in the range [0, x-1].

    // So the result of large calculations can be reduced to a smaller range using modulo arithmetic.
    // if the result is represent in the form (ans % 10**7 + 9), then the result will be in the range [0, 10**7 + 8].

    // SOME PROPERTIES OF MODULO ARITHMETICS:

    // 1. (a + b) % m = (a % m) + (b % m)
    // 2. (a - b) % m = (a % m) - (b % m)
    // 3. (a * b) % m = (a % m) * (b % m)
    
    // 4. ((((a % m) % m) % m)_ _ ) % m = a % m

    return 0;
}