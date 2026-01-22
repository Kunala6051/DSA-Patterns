#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10
using namespace std;

// Recursion: Calling a function within itself to solve a problem.
int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

void printN(int n) {
    if (n <= 0) return; // Base case
    printN(n - 1); // Recursive case
    cout << n << " "; // Print after the recursive call to ensure order
}

int sumOfn(int n){
    if(n== 1) return 1; // Base case
    return n + sumOfn(n - 1); // Recursive case
}

// Time Complexity: O(n) for all functions
// Space Complexity: O(n) for all functions due to recursion stack


// So, for all the functions, loops are the better approach due to lower space complexity

int main(){

    int n=6;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;

    cout << "Printing numbers from 1 to " << n << ": ";
    printN(n);

    // Memory management: Using stack memory for recursion.

    // Like the first function to be called is int main() and then it calls factorial.
    // The function factorial calls itself recursively until it reaches the base case.
    // Each recursive call adds a new layer to the stack, and once the base case is reached,
    // the stack unwinds, returning the result back through each layer of the recursion.
    // The process of comming back from the recursive calls is known as unwinding the stack or BACKTRACKING.


    // Recurrence Relation: A way to express a problem in terms of smaller subproblems.

    // For example, the printN function can be expressed as:
    // f(n) = print(n) + f(n-1)
    // T(n) =  O(1) + T(n-1), where T(n) is the time complexity of printing numbers from 1 to n.
    // Hence we can find the time complexity of printN function by solving the recurrence relation.


    // Time Complexity in Recursion:

    // 1. By Recurrence Relation:
    // The time complexity of the factorial function can be expressed as:
    // T(n) = T(n-1) + O(1), where T(n) is the time complexity of calculating factorial of n.
    // Hence we can find the time complexity of factorial function by solving the recurrence relation.

    // 2. Time Complexity = Total number of recursive calls * Work done in each call.
    // For factorial(n), the total number of recursive calls is n, and the work done in each call is O(1).
    // Therefore, the time complexity of factorial(n) is O(n).
    


    // Space Complexity in Recursion:

    // As we are using recursion, each recursive call adds a new layer to the stack.
    // So, the memory used by the recursion is proportional to the depth of the recursion.
    // Space Complexity = Height of the recursion tree * Memory used in each call.

    // For factorial(n), the height of the recursion tree is n, and the memory used in each call is O(1).
    // Hence, the space complexity of factorial(n) is O(n).


    cout << "\nSum of first " << n << " natural numbers is: " << sumOfn(n) << endl;

    return 0;
}