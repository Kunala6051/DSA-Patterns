#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <cmath> // For mathematical functions like log10

using namespace std;

void merge(vector<int>&nums, int l, int mid, int r){
    int i=l, j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=r){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        } else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }

    while(j<=r){
        temp.push_back(nums[j]);
        j++;
    }

    for(int k=0; k<temp.size(); k++){
        nums[k+l]=temp[k];
    }

}



void mergeSort(vector<int>&nums, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);

        merge(nums,l,mid,r);
    }
}

int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    int n = nums.size();
    mergeSort(nums,0,n-1);

    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}