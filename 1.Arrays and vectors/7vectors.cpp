#include <iostream>
#include <vector>
using namespace std;

// Vectors are dynamic in nature (their size can be changed)
// STL => Standard Template Library
// Vectors are allocated in memory at run-time.


// Linear Search on vectors
int linearSearch(vector<int> vec, int sz, int target){
    int targetIndex=-1;
    for(int i=0; i<sz; i++){
        if(vec[i]==target){
            targetIndex=i;
        }
    }

    return targetIndex;

}

// Reversing vectors
int reverse(vector<int> & vec, int sz){ // If we will not put this ampersand(&) vector will not change in main function. 
    int start=0, end=sz-1;              // So, to pass by reference & is used. 
    while(start<end){                   // (If it is passed by value, the original variable in main function does not undergo any change).
        swap(vec[start],vec[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> vec = {1,2,3}; // capacity = 3, size =3
    vector<int> vec2 (5,0); // (size,element)  output => [0,0,0,0,0]
    vector<char> vec3 = {'a','b','c'};

    for(int i=0; i<5; i++){
        cout << vec2[i] << " ";
    }
    cout << endl;
    cout << "Size of vec2: " << vec2.size() << endl;

    for(int i: vec){ // for each loop
        cout << i << " ";
    }
    cout << endl;

    for(char i: vec3){
        cout << i << " ";
    }
    cout << endl;

    // VECTOR FUNCTIONS
    
    cout << "Size: " << vec.size() << endl; 


    vec.push_back(40); // size of vec: 4, capacity of vec: 6
    vec.push_back(30); // size of vec: 5, capacity of vec: 6
    cout << "After push_back Size: " << vec.size() << endl;
    // MEMORY ALLOCATION OF VECTORS
    // When size of vector is changed: A new vector is stored in the memory with double capacity and the previous one is deleted.
    cout << "After push_back Capacity of vec: " << vec.capacity() << endl;

    vec.pop_back(); // size of vec: 4, capacity of vec: 6
    cout << "After pop_back Size: " << vec.size() << endl;
    cout << "After pop_back Capacity of vec: " << vec.capacity() << endl;

    for(int i: vec){ // for each loop
        cout << i << " ";
    }
    cout << endl;

    cout << vec.front() << endl;

    cout << vec.back() << endl;

    cout << vec.at(2) << endl; // Similar to vec[2]

    cout << "Capacity of vec: " << vec.capacity() << endl;


    // SINGLE NUMBER PROBLEM
    // every number has a duplicate except one, we have to find that number

    // Important: XOR (Bitwise operator) (0^0=0, 1^1=0, 0^1=1, 1^0=1)
    // also 2^2=0 (10^10=00) similarly 5^5=0 (101^101=000)
    // Therefore we will apply XOR operator on whole array

    vector<int> vec4 = {1,2,2,3,3,4,5,6,1,5,4};
    int result = 0;

    for(int i: vec4){
        result^=i; // same values will cancel and the single number will be left as output
    }
    cout << "Single Number: " << result;
    cout << endl;

    // Linear Search
    vector<int>  vec5={1,2,3,44,55,6,777};
    cout << "Index of 56: " << linearSearch(vec5, 7, 56) << endl;

    // Reversing
    reverse(vec5, 7);
    for(int i: vec5){ // for each loop
        cout << i << " ";
    }
    cout << endl;



    return 0;
}