# include <iostream>
using namespace std;

class Stack{
    int* arr;
    int topidx;
    int capacity;
public:
    Stack(int cap){
        capacity=cap;
        arr=new int[cap];
        topidx=-1;
    }
  
    void push(int val){
        if(topidx==capacity-1){

            cout << "Stack overflow" << endl;
            return;
        }
        topidx++;
        arr[topidx]=val;
    }

    void pop(){
        if(topidx==-1){
            cout << "Stack underflow" << endl;
            return;
        }
        topidx--;
    }

    int top(){
        if(topidx==-1){
            cout << "Stack is empty" << endl;
            return -1; // Return -1 to indicate stack is empty
        }
        return arr[topidx];
    }

    bool empty(){
        return topidx==-1;
    }

    void printstack(){
        for(int i=topidx; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s(5); // Stack with capacity of 5

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // This will cause stack overflow

    s.printstack();

    return 0;
}