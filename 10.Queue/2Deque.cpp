#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Demonstration of Deque (Double-Ended Queue) in C++
// A deque allows insertion and deletion of elements from both ends (front and back).

int main() {
    deque<int> dq;

    // Adding elements to the back of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Adding elements to the front of the deque
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque after adding elements:" << endl;
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Accessing front and back elements
    cout << "Front element: " << dq.front() << endl; // 1
    cout << "Back element: " << dq.back() << endl;   // 30

    // Removing elements from the front and back
    dq.pop_front(); // removes 1
    dq.pop_back();  // removes 30

    cout << "Deque after removing elements:" << endl;
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}