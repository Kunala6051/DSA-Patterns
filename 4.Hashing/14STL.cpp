#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// STL (Standard Template Library) is a powerful set of C++ template classes to provide general-purpose classes and functions.
// It includes algorithms, containers, functors and iterators.



// custom comparetor to sort pairs in ascending order

bool comparator1(pair<int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second ){
        return true;
    } else {
        return false;
    }
}



// if both second elements of pairs are equal thencompare on the basis of 1st

bool comparator2(pair<int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second ){
        return true;
    } 
    if (p1.second > p2.second) return false;

    if (p1.first < p2.first) return true;
    else return false;

}



int main(){

// 1. CONTAINERS

// Containers are data structures that store collections of objects, such as vectors, lists, and maps.

    // 1. VECTORS

    // Vector: A dynamic array that can grow and shrink in size.
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // size and capacity
    cout << "Vector size: " << vec.size() << endl; // Number of elements
    cout << "Vector capacity: " << vec.capacity() << endl; // Allocated memory size
    
    // push_back: Add an element to the end of the vector
    vec.push_back(6);

    // emplace_back: Add an element to the end of the vector (constructs in place)
    vec.emplace_back(7); // More efficient than push_back for complex objects

    // pop_back: Remove the last element from the vector
    vec.pop_back();



    cout << "Vector size: " << vec.size() << endl; // Number of elements
    cout << "Vector capacity: " << vec.capacity() << endl; // Allocated memory size

    // Accessing elements
    cout << "First element: " << vec[0] << endl; // Access using index
    cout << "Second element: " << vec.at(1) << endl; // Access using at() method
    cout << "Last element: " << vec.back() << endl; // Access the last element
    cout << "First element: " << vec.front() << endl; // Access the first element

    vector<int> vec2(vec); // Copy constructor
    vector<int> vec3(10,-1); // Initialize a vector of size 10 with all elements set to -1

    // Erase elements
    vec.erase(vec.begin() + 1); // Erase the second element
    // vec.begin() returns an iterator to the first element (the start of the vector)(just like a pointer)
    // vec.end() returns an iterator to one past the last element (element after the last element)

    // can also use erase with a range
    vec.erase(vec.begin() + 1, vec.begin() + 3); // Erase elements from the second to the third (exclusive)

    // insert elements
    vec.insert(vec.begin() + 1, 10); // Insert 10 at the second position

    // clear the vector
    vec.clear(); // Remove all elements from the vector

    // empty check
    if (vec.empty()) { // gives true if the vector is empty (prints 1) or false if it is not empty (prints 0)
        cout << "Vector is empty." << endl;
    } else {
        cout << "Vector is not empty." << endl;
    }

    // Dereferencing iterators
    cout << *vec2.begin() << endl; // Dereference the iterator to get the first element
    cout << *(vec2.end() - 1) << endl; // Dereference the iterator to get the last element

    // Iterating through the vector using a range-based for loop
    for (int value : vec2) {
        cout << value << " "; // Print each element
    }
    cout << endl;

    // Initiating iterators
    vector<int>::iterator it; // Create an iterator for the vector   
    vector<int>::reverse_iterator reverse_it; // Create a reverse iterator for the vector

    // Iterating through the vector using an iterator

    // auto keyword can be used to automatically deduce the type of the iterator
    // i.e. we don't need to specify the type of the iterator explicitly (vector<int>::iterator it)
    // modern C++ allows us to use `auto` to deduce the type of the iterator, whether it is a forward iterator, reverse iterator, or any other type of iterator.
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        cout << *it << " "; // Dereference the iterator to get the value
    }  
    cout << endl;

    // Using reverse iterator to iterate in reverse order
    for (reverse_it = vec2.rbegin(); reverse_it != vec2.rend(); ++reverse_it) {
        cout << *reverse_it << " "; // Dereference the reverse iterator to get the value
    }
    cout << endl;
    // if we would have write auto here, it would have been auto reverse_it = vec2.rbegin();

    // BY THESE ITERATORS, we can directly access the memory address of the elements in the vector
    cout << "Address of first element: " << &(*vec2.begin()) << endl; // Address of the first element


    // 2. LISTS

    // List: A doubly linked list that allows for efficient insertion and deletion of elements.
    // Note: Lists are not as commonly used as vectors in modern C++ due to their overhead and the fact that vectors are more cache-friendly.

    // Vectors are dynamic arrays that provide fast random access to elements, while lists are linked lists that allow for efficient insertion and deletion of elements at any position.
    
    list <int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6); // Add an element to the end of the list
    lst.push_front(0); // Add an element to the front of the list
    lst.pop_back(); // Remove the last element from the list
    lst.pop_front(); // Remove the first element from the list
    cout << "List size: " << lst.size() << endl; // Number of elements in the list
    cout << "List elements: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " "; // Print each element
    }
    cout << endl;

    // Lists support all the same operations(emplace_front, emplace_back etc) as vectors, such as inserting and erasing elements, but they do not support random access.

    
    // 3. DEQUE
    
    // Deque: A double-ended queue that allows for efficient insertion and deletion of elements at both ends.
    deque<int> deq = {1, 2, 3, 4, 5};   
    deq.push_back(6); // Add an element to the end of the deque
    deq.push_front(0); // Add an element to the front of the deque
    deq.pop_back(); // Remove the last element from the deque

    // Difference between deque and list:

    // Deques are similar to vectors but allow for efficient insertion and deletion at both ends, while lists are linked lists that allow for efficient insertion and deletion at any position.
    // Deques provide random access to elements, while lists do not.
    // Random access means that we can access any element in the deque using an index, just like we do with vectors.
    cout << deq[0] << endl; // Access the first element using index
    // cout << lst[0] << endl; // Access the first element using index (not supported in lists, will give error)
    


    // 4. PAIR

    // Pair: A simple container that holds two values of different types.

    pair<int, string> p = make_pair(1, "Hello"); // Create a pair using make_pair
    pair<int, char> p2 = {2, 'A'}; // Create a pair using initializer list (more common in modern C++)
    cout << "Pair: " << p.first << ", " << p.second << endl; // Access the first and second elements of the pair

    pair <int, pair<int,char>> nestedPair = {2, {3, 'A'}}; // Nested pair
    cout << "Nested Pair: " << nestedPair.first << ", " << nestedPair.second.first << ", " << nestedPair.second.second << endl; // Access the elements of the nested pair


    // pairs in vectors
    vector<pair<int, string>> vecPairs = {{1, "One"}, {2, "Two"}, {3, "Three"}};


    for (pair<int, string> p : vecPairs) {
        cout << p.first << ": " << p.second << endl; // Access the first and second elements of each pair
    }

    vecPairs.push_back({1,"four"}); // Add a new pair to the vector
    vecPairs.emplace_back(5, "five"); // Add a new pair to the vector using emplace_back

    // notice difference between push_back and emplace_back
    // push_back creates a temporary pair object and then copies it into the vector
    // while emplace_back constructs the pair in place, avoiding the copy.

    cout << "Vector of pairs: " << endl;
    for (auto p : vecPairs) {
        cout << p.first << ": " << p.second << endl; // Access the first and second elements of each pair
    }


    // 5. STACK

    // Stack: A last-in, first-out (LIFO) data structure that allows for efficient insertion and deletion of elements at the top.
    stack<int> st; // Create a stack of integers
    st.push(1); // Add an element to the top of the stack
    // emplace does the same thing
    st.emplace(2); // Add another element to the top of the stack
    st.push(3); // Add another element to the top of the stack

    cout << "Stack top: " << st.top() << endl; // Access the top element of the stack

    st.pop(); // Remove the top element from the stack

    cout << "Stack size: " << st.size() << endl; // Number of elements in the stack

    while (!st.empty()) { // Check if the stack is empty
        cout << st.top() << " "; // Print the top element of the stack
        st.pop(); // Remove the top element from the stack
    }
    cout << endl; // Print a new line after printing all elements in the stack
    // Note: Stacks do not support random access, so we cannot access elements in the middle of the stack.

    // swapping two stacks
    stack<int> st2; 
    st2.push(4);
    st2.push(5);
    st.swap(st2); // Swap the contents of two stacks
    
    // Now st contains 4 and 5, and st2 contains nothing
    cout << "Size of st after swap: " << st.size() << endl; // Size of the stack after swap
    cout << "Size of st2 after swap: " << st2.size() << endl; // Size of the stack after swap


    
    // 6. QUEUE

    // Queue: A first-in, first-out (FIFO) data structure that allows for efficient insertion and deletion of elements at the front and back.

    queue<int> q; // Create a queue of integers
    q.push(1); // Add an element to the back of the queue
    q.emplace(2); // Add another element to the back of the queue
    q.push(3); // Add another element to the back of the queue

    cout << "Queue front: " << q.front() << endl; // Access the front element of the queue
    cout << "Queue back: " << q.back() << endl; // Access the back element of the queue
    cout << "Queue size: " << q.size() << endl; // Number of elements in the queue

    q.pop(); // Remove the front element from the queue


    // 7. PRIORITY QUEUE (Visualize it as a stack with priority)

    // Priority Queue: A data structure that allows for efficient insertion and deletion of elements based on their priority.
    priority_queue<int> pq; // Create a max-heap priority queue of integers

    // By default, priority queue is a max-heap, meaning the largest element has the highest priority.

    // There are two types of Complete Binary Trees:
    // 1. Max-Heap: The parent node is always greater than or equal to its children.
    // 2. Min-Heap: The parent node is always less than or equal to its children.

    pq.push(3); // Add an element to the priority queue
    pq.emplace(10); // Add another element to the priority queue
    pq.push(5); 
    pq.push(1); 
    pq.push(7); 
    

    cout << "Priority Queue top: " << pq.top() << endl; // Access the top element of the priority queue (highest priority)
    
    pq.pop(); // Remove the top element from the priority queue (10 in this case)

    while(!pq.empty()) { // Check if the priority queue is empty
        cout << pq.top() << " "; // Print the top element of the priority queue
        pq.pop(); // Remove the top element from the priority queue
    }
    cout << endl; 

    priority_queue<int, vector<int>, greater<int>> pq2; // Create a min-heap priority queue of integers

    // The third template parameter is the comparison function(functor), which is used to determine the priority of elements.
    // In this case, we are using greater<int> to create a min-heap priority queue.

    pq2.push(3); // Add an element to the priority queue
    pq2.emplace(10); // Add another element to the priority queue
    pq2.push(5); 
    pq2.push(1); 
    pq2.push(7); 

    while(!pq2.empty()) { // Check if the priority queue is empty
        cout << pq2.top() << " "; // Print the top element of the priority queue
        pq2.pop(); // Remove the top element from the priority queue
    }
    cout << endl;

    // Time Complexity of Priority Queue Operations:
    // push/emplace: O(log n) - Inserting an element into the priority queue takes logarithmic time.
    // pop: O(log n) - Removing the top element from the priority queue takes logarithmic time.
    // top: O(1) - Accessing the top element of the priority queue takes constant time.

    // (In stack and queue, push and pop operations take O(1) time, while top/front/back operations take O(1) time as well.)


    // 8. MAP

    // Map: A data structure that stores key-value pairs, where each key is unique and maps to a value.
    map<int, string> mp; // Create a map of integers to strings

    mp[1] = "One"; // Insert a key-value pair into the map
    mp[2] = "Two"; 
    mp[3] = "Three"; 

    mp.insert({4, "Four"}); // Insert another key-value pair into the map using insert() method
    mp.emplace(5, "Five"); // Insert another key-value pair into the map using emplace() method

    // if we try to access a key which is already present in the map, it will update the value of that key
    mp[2] = "Two Updated"; // Update the value for key 2

    cout << "Map size: " << mp.size() << endl; // Number of key-value pairs in the map

    cout << "Map elements: " << endl;
    for (auto p : mp) {
        cout << p.first << ": " << p.second << endl; // Access the key and value of each pair in the map
    }

    // Accessing elements in the map

    cout << "Value for key 2: " << mp[2] << endl; // Access the value for a specific key
    cout << "Value for key 6 (not present): " << mp[6] << endl; // Accessing a key that is not present will insert a new key with a default value (empty string in this case)

    // finding elements in the map
    if (mp.find(3) != mp.end()) { // Check if the key was found
        cout << "Found key 3 with value. " << endl;
    } else {
        cout << "Key 3 not found." << endl;
    }

    // if the key is not present in the map, it will return an iterator to the end of the map(1 after the last element)

    // Erasing elements from the map
    mp.erase(2); // Erase the key-value pair with key 2

    map<string, int> mp2; 
    mp2["apple"] = 5; // Insert a key-value pair into the map
    mp2["banana"] = 3; // Insert another key-value pair into the map
    mp2["orange"] = 8; // Insert another key-value pair into the map
    mp2["kiwi"] = 2; // Insert another key-value pair into the map

    if(mp2.find("banana") != mp2.end()) {
        cout << "Found key 'banana' with value: " << mp2["banana"] << endl; // Access the value for key "banana"
    } else {
        cout << "Key 'banana' not found." << endl;
    }

    // Count the number of elements with a specific key
    cout << "Count of key 'banana': " << mp2.count("banana") << endl; // Count the number of elements with key "banana"

    cout << "Map 2 elements: " << endl;
    for (auto p : mp2) {
        cout << p.first << ": " << p.second << endl; // Access the key and value of each pair in the map
    } // See that the keys are sorted in ascending order

    // Maps are ordered by keys, so the elements will be printed in ascending order of keys.
    // The time complexity of map operations is O(log n) for insertion, deletion, and search operations.


    // i. MULTIMAP (Rarely used)

    // Multimap: A data structure that allows for multiple values to be associated with the same key.
    multimap<string, int> mmp;

    // Can use insert() or emplace() to add elements
    mmp.insert({"tv", 25}); // Insert a key-value pair into the multimap
    mmp.emplace("tv", 10); // Insert another key-value pair with the same key
    mmp.insert({"tv", 15}); // Insert another key-value pair with the same key

    cout << "Multimap elements: " << endl;
    for (auto p : mmp) {
        cout << p.first << ": " << p.second << endl; // Access the key and value of each pair in the multimap
    }
    // (If it would have been a map, only one value would have been associated with the key "tv", but in a multimap, multiple values can be associated with the same key.)

    // erasing elements from the multimap

    mmp.erase(mmp.find("tv")); // Erase the first occurrence of the key "tv"
    // Note: If there are multiple occurrences of the key "tv", only the first occurrence will be erased.

    mmp.erase("tv"); // Erase all key-value pairs with key "tv"


    // ii. UNORDERED MAP (Most commonly used)

    // Unordered Map: A data structure that stores key-value pairs in an unordered manner (random), allowing for faster access.
    // No duplicate keys are allowed, and the keys are not sorted.
    unordered_map<int, string> ump; // Create an unordered map of integers to strings   

    ump[1] = "One"; // Insert a key-value pair into the unordered map
    ump[2] = "Two";
    ump[3] = "Three";
    ump.insert({4, "Four"}); // Insert another key-value pair into the unordered map using insert() method
    ump.emplace(5, "Five"); // Insert another key-value pair into the unordered map using emplace() method

    ump[2] = "Two Updated"; // Update the value for key 2

    for(auto p : ump) {
        cout << p.first << ": " << p.second << endl; // Access the key and value of each pair in the unordered map
    }

    // Difference between map and unordered_map:

    // Maps are ordered by keys, while unordered maps are unordered.
    // Maps use a self balancing binary search tree (usually red-black tree) to store elements, therfore the time complexity of map operations(insert,erase,count) is O(log n).
    // Unordered maps use a hash table to store elements, therefore the time complexity of unordered_map operations(insert,erase,count) is O(1) on average.
    // However, in the worst case, the time complexity can be O(n) if there are many collisions in the hash table.
    // Unordered maps are generally faster than maps for most operations, but they do not maintain the order of elements.


    // 9. SET

    // Set: A data structure that stores unique elements in a sorted order.
    set<int> s; // Create a set of integers

    s.insert(1); // Insert an element into the set
    s.emplace(2); // Insert another element into the set
    s.insert(3);
    s.insert(100);
    s.insert(5);

    s.insert(1);
    s.insert(2);
    s.insert(3); // Duplicate elements are ignored in a set

    cout << "Set size: " << s.size() << endl; // Number of unique elements in the set

    cout << "Set elements: ";
    for (int value : s) {
        cout << value << " "; // Print each unique element in the set
    }
    cout << endl;

    // Sets are ordered by default, so the elements will be printed in ascending order.

    // Accessing elements in the set
    cout << "First element: " << *s.begin() << endl; // Access the first element of the set
    cout << "Last element: " << *s.rbegin() << endl; // Access the last element of the set

    // Note: Sets do not support random access, so we cannot access elements in the middle of the set.

    // Erasing elements from the set
    s.erase(2); // Erase the element with value 2 from the set

    // Finding elements in the set
    if (s.find(3) != s.end()) { // Check if the element 3 is present in the set
        cout << "Found element" << endl;
        cout << "Returning value of found element " << *s.find(3) << endl; // Access the value of the found element
    } else {
        cout << "Element 3 not found." << endl;
    }

    // Time Complexity of Set Operations are same as that of Map Operations:
    // insert,erase,count: O(log n) 


    // lower_bound and upper_bound in set:

    // lower_bound: Returns an iterator to the first element that is EQUAL TO or JUST GREATER THAN the given value.
    // upper_bound: Returns an iterator to the first element that is GREATER than the given value.

    // Iterators returned by lower_bound and upper_bound can be dereferenced to get the value.

    cout << "Lower bound of 3: " << *s.lower_bound(3) << endl; // Returns the first element that is greater than or equal to 3
    cout << "Upper bound of 3: " << *s.upper_bound(3) << endl; // Returns the first element that is greater than 3

    // If the value greater than the element does not exist, it will return the end iterator and when we will dereference it, it will give a random value or cause undefined behavior.

    cout << "Upper bound of 100: " << *s.upper_bound(100) << endl; // Returns the first element that is greater than 100

    cout << "Lower bound of 101: " << *s.lower_bound(101) << endl; // Returns the first element that is greater than or equal to 101

    // Incase of alphabets, lower_bound and upper_bound will return the first element that is greater than or equal to the given character.
    // For example, if the set contains {'a', 'b', 'c'}, then lower_bound('b') will return 'b' and upper_bound('b') will return 'c'.


    // Unordered Set: A data structure that stores unique elements in an unordered manner (random), allowing for faster access.
    unordered_set<int> us; // Create an unordered set of integers

    // Multiset: A data structure that allows for multiple occurrences of the same element.
    multiset<int> ms; // Create a multiset of integers

    // Both unordered_set and multiset are similar to unordered_map and multimap, respectively, but they do not store key-value pairs.
    // Time complexity of unordered_set and multiset operations (insert, erase, find) is O(1) on average, but can be O(n) in the worst case due to hash collisions.





    // ALGORITHMS

    // Algorithms are functions that perform operations on containers, such as sorting, searching, and manipulating elements.


    // 1. SORTING
    // Sorting: Rearranging elements in a specific order (ascending or descending).

    vector<int> arr = {5, 2, 8, 1, 3};
    sort(arr.begin(), arr.end()); // Sort the array in ascending order using the sort() function
    
    cout << "Sorted array: ";
    for (int value : arr) {
        cout << value << " "; // Print each element of the sorted array
    }
    cout << endl;

    // To sort in descending order, we can use the greater<int>() comparator(Functor) as the third argument to the sort() function.
    sort(arr.begin(), arr.end(), greater<int>()); // Sort the array in descending order

    cout << "Sorted array in descending order: ";
    for (int value : arr) {
        cout << value << " "; // Print each element of the sorted array
    }
    cout << endl;

    // sorting is done in O(n log n) time complexity and O(1) space complexity.


    // sorting arrays

    int arr2[] = {5, 2, 8, 1, 3};

    int n = sizeof(arr2) / sizeof(arr2[0]); // Calculate the size of the array

    sort(arr2, arr2 + n); // Sort the array in ascending order using the sort() function

    // arr2 + n gives the address of the element after the last element of the array, which is used as the end iterator for the sort() function.
    // as 2nd argument is not inclusive, it will not include the last element in the sorting process.
    cout << "Sorted array: ";  
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " "; // Print each element of the sorted array
    }
    cout << endl;

    // sorting vectors of pairs

    vector<pair<int, int>> vecPairs2 = {{3, 11}, {1, 6}, {2, 5}, {20, 5}, {12, 5}};
    vector<pair<int, string>> vecPairs3 = {{3, "Three"}, {1, "One"}, {2, "Two"}};

    // Sort the vector of pairs based on the first element of each pair (the integer)
    sort(vecPairs2.begin(), vecPairs2.end()); // Sort the vector of pairs in ascending order based on the first element

    cout << "Sorted vector of pairs: " << endl;
    for (auto p : vecPairs2) {
        cout << p.first << ": " << p.second << endl; // Access the first and second elements of each pair in the sorted vector
    }


    cout << "Sorted vector of pairs by comparator1: " << endl;
    sort(vecPairs2.begin(), vecPairs2.end(), comparator1); // sorting with the help of our custom comperator
    // sorts pairs based on second value

    for (auto p : vecPairs2) {
        cout << p.first << ": " << p.second << endl; // Access the first and second elements of each pair in the sorted vector
    }

    cout << "Sorted vector of pairs by comparator2: " << endl;
    sort(vecPairs2.begin(), vecPairs2.end(), comparator2); // sorting with the help of our custom comperator
    // sorts pairs based on second value

    for (auto p : vecPairs2) {
        cout << p.first << ": " << p.second << endl; // Access the first and second elements of each pair in the sorted vector
    }



    // 2. REVERSING
    // Reversing: Reversing the order of elements in a container.

    reverse(arr.begin(), arr.end()); // Reverse the order of elements in the array using the reverse() function
    cout << "Reversed array: ";
    for (int value : arr) {
        cout << value << " "; // Print each element of the reversed array
    }
    cout << endl;

    reverse(arr.begin()+1, arr.begin()+4); // Reverse the order of elements from index 1 to index 3 (exclusive) in the array
    cout << "Reversed array from index 1 to 3: ";   
    for (int value : arr) {
        cout << value << " "; // Print each element of the reversed array
    }
    cout << endl;

    // 3. NEXTPERMUTATION And PREVIOUSPERMUTATION
    // Next Permutation: Generates the next lexicographical permutation of the elements in a container.

    string str = "abc";

    next_permutation(str.begin(), str.end()); // Generate the next lexicographical permutation of the string
    cout << "Next permutation of 'abc': " << str << endl; // Print the next permutation of the string

    // If the string is already the last permutation, it will wrap around to the first permutation.
    prev_permutation(str.begin(), str.end()); // Generate the previous lexicographical permutation of the string
    cout << "Previous permutation of 'abc': " << str << endl; // Print the previous permutation of the string

    // Note: next_permutation and prev_permutation functions return true if the permutation was successfully generated, and false if it was not possible to generate the next or previous permutation.


    // 4. swap, min, max

    cout << "Min of 5 and 10: " << min(5, 10) << endl; // Find the minimum of two values
    cout << "Max of 5 and 10: " << max(5, 10) << endl; // Find the maximum of two values

    int a = 5, b = 10;
    swap(a, b); // Swap the values of a and b using the swap() function
    cout << "After swapping, a: " << a << ", b: " << b << endl; // Print the values of a and b after swapping


    // 5. MIN / MAX ELEMENTS

    vector<int> vec4 = {1, 2, 3, 4, 5};
    auto minElement = *min_element(vec4.begin(), vec4.end()); // Find the minimum element in the vector
    auto maxElement = *max_element(vec4.begin(), vec4.end()); // Find the maximum element in the vector

    // min_element and max_element RETURN AN ITERATOR to the minimum and maximum elements, respectively, so we need to dereference it to get the value.


    // 6. BINARY SEARCH
    // Binary Search: A search algorithm that finds the position of a target value within a sorted array.

    vector<int> sortedArr = {1, 2, 3, 4, 5};
    int target = 3;
    cout << "Result of binary search: " << binary_search(sortedArr.begin(), sortedArr.end(), target) << endl; // Perform binary search on the sorted array
    // binary_search returns true if the target value is found in the array, and false if it is not found.
    // Note: The array must be sorted before performing binary search, otherwise it will not work correctly.


    // 7. BITS COUNTING

    // Counting Bits: Counting the number of set bits (1s) in a binary representation of a number.
    int num = 29; // Binary representation: 11101
    int count = __builtin_popcount(num); // Count the number of set bits in the binary representation of the number
    cout << "Number of set bits in " << num << ": " << count << endl; // Print the number of set bits

    long int num2 = 123456789; // Binary representation: 111010110111100110100010101
    int count2 = __builtin_popcountll(num2); // Count the number of set bits in the binary representation of the long integer
    cout << "Number of set bits in " << num2 << ": " << count2 << endl; // Print the number of set bits in the long integer

    long long int num3 = 1234567890123456789; // Binary representation: 100010110001110011101111000110001010101010111001
    int count3 = __builtin_popcountll(num3); // Count the number of set bits in the binary representation of the long long integer
    cout << "Number of set bits in " << num3 << ": " << count3 << endl; // Print the number of set bits in the long long integer

    // se the difference between popcount and popcountll
    // __builtin_popcount is used for 32-bit integers, while __builtin_popcountll is used for 64-bit integers.
    
    
    return 0;
}