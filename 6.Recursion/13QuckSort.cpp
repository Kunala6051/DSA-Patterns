// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivot(vector<int>&arr, int l, int h){
    int p=arr[h];
    int i=0;
    for(int j=0; j<arr.size()-1; j++){
        if(arr[j]<p){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[h]);
    return i;
}

void quickSort(vector<int>&arr, int l, int h){
    if(l<h){
        int pi=pivot(arr,l,h);
        
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,h);
    }
}

int main() {
    // Write C++ code here
    vector <int> arr={1,4,0, 0,90,100,-9999,-90,80};
    quickSort(arr,0,8);
    for(int i: arr) cout << i << " ";

    return 0;
}