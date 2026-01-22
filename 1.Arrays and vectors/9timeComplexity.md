TIME COMPLEXITY => NOT the actual time taken but the amount of time taken as function of input size (n).
while talking about TC we generally talk about worst case scenarios(eg. in linear search if the target element is present at last index or does not exists loop has to iterate through full array.)


Reason to find Time complexity:
It is important beacause while building big algorithms we want to check the behaviour on large number of inputs.
To compare two algorithms that which takes more time.


Big O notation (Upper Bound) (Worst Case Scenario)
Steps to find Time Complexity 
For eg the f(n) = 3n^2 + 4n + 923.

Step 1 => Ignore constants => n^2 + n
Step 2 => Largest Term => n^2
TIME COMPLEXITY => O(n^2)


Notation for best Case Scenario(Lower Bound) => Omega
Notation for Average Case Scenario => Theta



SPACE COMPLEXITY => Space[Auxiliary => Other than input(Vector, String, Array etc)] taken but the amount of time taken as function of input size (n).

eg. You are given an array and have to make a new array with the squares of the elements. For n number of inputs n new elements will be made in an array, so Space complexity of this algorithm will be O(n).

O(K) => Find the sum of 1st n numbers. A single variable will be made (ans = n * (n+1)/2). So it does not depends upon the number of input, therefore space complexity => O(K) =>  O(K)


SOME COMMON TIME COMPLEXITIES:
BEST => O(1) > O(logn) > O(n) > O(nlogn) > O(n^2) > O(n^3) > O(2^n) > O(n!) (n factorial)

video watched till 40 min.