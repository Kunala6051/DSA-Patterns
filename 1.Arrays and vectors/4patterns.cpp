#include <iostream>
using namespace std;

int main() {

// 0 1 2 3 
// 0 1 2 3
// 0 1 2 3
// 0 1 2 3
    int n=4;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

// A B C D
// A B C D
// A B C D
// A B C D    
    for (int i=0; i<n; i++){
        char c='A';
        for (int j=0; j<n; j++){
            cout << c << " ";
            c = c+1;
        }
        cout << endl;
    }
    cout << endl;
      

// 1 2 3
// 4 5 6
// 7 8 9
    int k=3;
    int num=1;
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


// A B C
// D E F
// G H I
    char b='A';
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            cout << b << " ";
            b+=1;
        }
        cout << endl;
    }
    cout << endl;


// *
// * *
// * * *
// * * * *
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<i+1; j++){
            cout << "* ";
            
        }
        
        cout << endl;
    }
    cout << endl;


// 1
// 2 2
// 3 3 3 
// 4 4 4 4
    
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<i+1; j++){
            cout << i+1 << " ";
            
        }
        
        cout << endl;
    }
    cout << endl;



// 1
// 2 2
// 3 3 3 
// 4 4 4 4
    int count=0;
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<i+1; j++){
            cout << count << " ";
            
        }
        count++;
        
        cout << endl;
    }
    cout << endl;


// A
// B B
// C C C
// D D D D
    char c='A';
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<i+1; j++){
            cout << c << " ";
            
        }
        c+=1;
        
        cout << endl;
    }
    cout << endl;

// 1
// 1 2
// 1 2 3
// 1 2 3 4
    for (int i=0; i<n; i++) {
        
        for (int j=1; j<i+2; j++){ // here we are initiializing j=1
            cout << j << " ";
            
        }
        
        cout << endl;
    }
    cout << endl;


// 1
// 1 2
// 1 2 3
// 1 2 3 4
    for(int i=0; i<n; i++){
        int count1=1;
        for(int j=0; j<=i;j++){
            cout << count1 << " ";
            count1++;
        }

        cout << endl;
    }
    cout << endl;

    cout << "Reverse triangle pattern\n"; 
    for(int i=0; i<n; i++){
        for(int j=i+1; j>0;j--){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    
    for (int i=0; i<n; i++) {
        char d='A';
        d+=i;
        for (int j=0; j<i+1; j++){
            cout << d << " ";
            d--;
        }
        cout << endl;
    }
    cout << endl;

    

    //Floyd's triangle pattern 
    cout << "Floyd's triangle pattern\n"; 
    int num3=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++){
            cout << num3 << " ";
            num3++;
        }
        cout << endl;
    }
    cout << endl;
    
    char e='A';
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++){
            cout << e << " ";
            e++;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Inverted triangle pattern\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            cout << " ";
        }
        for (int j=0; j<n-i; j++){
            cout << i+1;
        }
        cout << endl;
    }
    cout << endl;

    
    
    return 0;



    // STILL PENDING
}