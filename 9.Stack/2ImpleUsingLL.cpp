#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Stack{
    list<int> ll;

public:
    void push(int val){   // O(1)
        ll.push_front(val);
        // Why we didnt use push_back here???
        // Because we want our head(top) to be the latest element pushed
        // by push_front head is also updated
    }

    void pop(){   // O(1)
        ll.pop_front(); // delete and update head;
    }

    int top(){    // O(1)
        return ll.front(); // return the first element of the list
    }

    bool empty(){
        return ll.size()==0;
    }
    // All these size, front, pop_front, push_front are pre defined functions of List class of STL 
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;


    return 0;

}