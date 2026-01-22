# include <iostream>
#include <unordered_set>
using namespace std;

// Arrays are allocated in memory at the time of compilation.
// Arrays are static in nature (their size can not be changed).

//  2 pointer Approach to Reverse an array
void reverseArray(int arr[], int sz){
    int start = 0, end = sz-1;

    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){

    int marks[5] = {99, 98, 100, 98, -100}; // [5] => size of array
    float price[] = {77.8, 33.56, 71};

    // Alternate way to find size of array
    int sizeOfPrice = sizeof(price) / 4; // one value of array(in case of int and float) stores 4 bytes and n values store 4*n bytes.
    cout << sizeOfPrice << endl;
    cout << sizeof(price) << endl;

    // can change values using index
    marks[0]=100;
    for(int i=0; i<5; i++){
        cout << marks[i] << endl;
    }



    // Taking array as input

    // int size;
    // cout << "Enter size of your array: ";
    // cin >> size;
    // int array[size];
    // for(int i=0; i<size; i++){
    //     cin >> array[i];
    // }
    // for(int i=0; i<size; i++){
    //     cout << array[i] << endl;
    // }



    // finding smallest and largest value 

    int smallest = INT16_MAX; // +infinity
    int largest = INT16_MIN; // -infinity
    // for(int i=0; i < 5; i++){ 

    //     if(marks[i] < smallest){
    //         smallest = marks[i];
    //     } 

    //     if(marks[i] > largest){
    //         largest = marks[i];
    //     }
    // }
    // cout << "Minimum marks: "<< smallest << endl;
    // cout << "Maximum marks: "<< largest << endl;

    // Alternate way
    for(int i=0; i < 5; i++){
        smallest = min(marks[i], smallest); // result of min (pre defined function to compare two numbers) will store in variable
        largest = max(marks[i], largest);
    }
    cout << "Minimum marks: "<< smallest << endl;
    cout << "Maximum marks: "<< largest << endl;

    // Linear Search
    // Using Linear Search to find the targetted element

    int array2[10]={1,22,3,4,5,6,7,8,9,100};
    // int target;
    // cout << "Enter Target Element: ";
    // cin >> target;
    // int targetIndex=0;
    // for(int i=0; i < 10; i++){
    //     if (array2[i]==target){
    //         targetIndex = i;
    //     }
    // }
    // if(targetIndex==0){
    //     targetIndex=-1;
    // }
    // cout << targetIndex << endl;

    // TIME COMPLEXITY FOR LINERA SEARCH => 0(n)


    // Reversing an array
    for(int i=0; i < 5; i++){
        swap(array2[i],array2[9-i]);
    }
    
    cout << "Reversed Array: ";
    for(int i=0; i < 10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;


    //  2 pointer Approach 
    reverseArray(array2, 10);

    cout << "REreversed Array: ";
    for(int i=0; i < 10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    
    // TIME COMPLEXITY => 0(n)

    
    // Calculating Sum
    int sum=0;
    int product=1;
    for (int i=0; i<10; i++){
        sum+=array2[i];
        product*=array2[i];
    }
    cout << "Sum of values of array2: " << sum << endl;
    cout << "Product of values of array2: " << product << endl;



    // SWAPPING MIN AND MAX OF AN ARRAY

    int smallest2 = INT16_MAX; // +infinity
    int largest2 = INT16_MIN; // -infinity

    int array[]={1,2,3,4,5,6};

    for(int i=0; i<6; i++){
        smallest2 = min (array[i],smallest2);
        largest2 = max (array[i],largest2);

    }

    int indexOfSmallest=0;
    int indexOfLargestest=0;

    for(int i=0; i < 6; i++){         // Finding index of largest and smallest so that they can be swapped
        if (array[i]==smallest2){
            indexOfSmallest = i;
        } else if (array[i]==largest2){
            indexOfLargestest = i;
        }
    }

    swap(array[indexOfSmallest], array[indexOfLargestest]);
    

    for(int i=0; i < 6; i++){
        cout << array[i] << " ";
    }
    cout << endl;


    // PRINTING ALL UNIQUE VALUES OF AN ARRAY

    int array3[] = {1,1,5,2,3,3,4,4,5,5,6,6,7,8,8,7,9};

    cout << "Unique Values: ";

    for(int i=0; i<sizeof(array3)/4; i++){


        bool isUnique = true;
        for(int j=0; j<sizeof(array3)/4; j++){

            if(i!=j){
                if(array3[i]==array3[j]){
                    isUnique = false;
                }
            }
            
        }


        if(isUnique){
            cout << array3[i] << " ";
        }
    }
    cout << endl;



    // Printing INTERSECTION(Common Elements) of two arrays

    int array4[] = {1,2,3,4,5,6,6,7};
    int array5[] = {5,6,7,8,9,10};
    unordered_set <int> s;
    cout << "Intersection: ";

    for(int i=0; i<sizeof(array4)/4; i++){
        for(int j=0; j<sizeof(array5)/4; j++){
            if (array4[i]==array5[j]){
                // If element is not already included
                if(s.find(array4[i]) == s.end()) cout << array4[i] << " ";
                s.insert(array4[i]);
            }
        }
    }
    cout << endl; 


    

    // Printing all subarrays (Time complexity: O(n^3))
    int array6[]={1,2,3,-4,5};
    for (int start=0; start<5; start++){
        for(int end=start; end<5; end++){
            for(int i=start; i<=end; i++){
                cout << array6[i];
            }
            cout  << " ";
        }
        cout << endl; 
    }

    // Brute Force Approach  (Time complexity: O(n^3))
    int maxSum = INT16_MIN;
    
    for (int start=0; start<5; start++){ 
        for(int end=start; end<5; end++){
            int crntSum = 0;
            for(int i=start; i<=end; i++){
                crntSum+=array6[i];
            }
            maxSum = max(crntSum,maxSum);
        }
    }

    // Brute Force Approach  (Time complexity: O(n^2)) [Better]
    int maxSum = INT16_MIN;
    
    for (int start=0; start<5; start++){
        int crntSum = 0;
        for(int end=start; end<5; end++){
            crntSum+=array6[end];  // Adding element and simultaneously updating the maximum
            maxSum = max(crntSum,maxSum);
        }
    }
    cout << "MAXIMUM SUBARRAY SUM: " << maxSum << endl;

    // Kadane's Algorithm (Most Optimised) (TIME COMPLEXITY => O(n))
    maxSum = INT16_MIN;
    int crntSum = 0;
    for(int i=0; i<5; i++){
        crntSum+=array6[i];
        maxSum = max(crntSum,maxSum); // thats why we already wrote this step earlier so that least negative term remains as a result.
        if(crntSum<0){ // If all elements are negative then crntSum becomes 0. Above is the solution
            crntSum=0; 
        }
    }
    // When all numbers are negative, above approach gives the lowest negative number
    // But in some compilers we are expected to return 0, in that case so just write the if condition after updating crntSum 
    cout << "MAXIMUM SUBARRAY SUM: " << maxSum << endl;




    return 0;
}
