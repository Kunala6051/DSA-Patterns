#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MY TRIAL OF target SUM
vector<int> targetSum(int arr[], int sz, int targetSum){
    
     int starting=0;
     int ending=0;

     for (int start=0; start<sz; start++){
        int crntSum = 0;
        for(int end=start; end<sz; end++){
            crntSum+=arr[end];
            if (crntSum==targetSum){
                starting=start;
                ending=end;
            }
        }
    }

    vector <int> vec={};
    for(int i=starting; i<=ending; i++){
        vec.push_back(arr[i]);
    }
    return vec;
}

// PAIR SUM: Given a sorted array find a pair who has a target sum

// BRUTE FORCE APPROACH (TIME COMPLEXITY: O(n^2))
vector <int> pairSum(int arr[], int sz, int targetSum){
    vector <int> vec={};
    for (int i=0; i<sz; i++){
        
        for(int j=i+1; j<sz; j++){
            if (arr[i]+arr[j]==targetSum){
                vec.push_back(arr[i]);
                vec.push_back(arr[j]);
                return vec; // ending the loop because multiple pairs can have target sum.
            }
        }
    }
    return vec;
}

// 2 Pointer Approach (Time complexity: O(n))

vector<int> pairSum2(int arr[], int sz, int targetSum){
    vector <int> vec={};
    int i=0, j=sz-1;
    while(i<j){
        int pair_sum=arr[i]+arr[j];
        if(pair_sum < targetSum){
            i++;
        } else if(pair_sum > targetSum){
            j--;
        } else{
            vec.push_back(arr[i]);
            vec.push_back(arr[j]);
            return vec;
        }
    }
}


// MAJORITY ELEMENT [Assume majority element alays exists]

// BRUTE FORCE APPROACH (TIME COMPLEXITY: O(n^2))
int majority(int arr[], int sz){
    int majorityElement=-1;
    for(int i=0; i<sz; i++){
        int frequency=0;
        for(int j=0; j<sz; j++){
            if(arr[j]==arr[i]){
                frequency++;
            }
            
        }
        if(frequency>sz/2){
            majorityElement=arr[i];
        }
    }
    return majorityElement;
}

// Approach based on sorting (TIME COMPLEXITY: O(nlogn))
int majoritySort(vector<int> vec, int sz){
    int frq=1;
    int ans=vec[0];
    sort(vec.begin(), vec.end());

    // for (int num : vec) {   // Checking if sorted or not
    //         cout << num << " ";
    //     }
    // cout << endl;

    for(int i=1; i<sz; i++){
        if(vec[i]==vec[i-1]){
            frq++;
        } else {
            frq=1;
            ans=vec[i];
        }

        if(frq>sz/2){
            return ans;
        }

    }

    return ans; 
}

// Moores's Voting Algorithm (TIME COMPLEXITY: O(n))

int majorityMoores(vector<int> & vec, int sz){    // some mistake in it
    int frq=0, ans=0;
    for(int i=0; i<sz; i++){

        if(frq==0){
            ans=vec[i];
        }

        if(ans==vec[i]){  
            frq++;
        } else{
            frq--;
        }

    }
    return ans;
}

int main() {
    int arr[]={1,2,3,4,5,6,7};
    
    vector<int> result = targetSum(arr, 7, 22);
    vector<int> result2 = pairSum(arr, 7, 13);
    vector<int> result3 = pairSum2(arr, 7, 10);

    int arr2[]={1,2,2,3,3,3,3};
    cout << "Majority Element: " << majority(arr2, 7) << endl;

    vector<int> vec={1,5,5,5,5,1,2,2,2,2,3,5,1};
    vector<int> vec4={1,2,2,1,1};
    cout << "Majority Element by sorting: " << majoritySort(vec, 13) << endl;
    cout << "Majority Element Moores's Voting Algorithm: " << majorityMoores(vec, 13) << endl;

    // Print the vector
    if (result.empty()) {
        cout << "No subarray found." << endl;
    } else {
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    if (result2.empty()) {
        cout << "No subarray found." << endl;
    } else {
        for (int num : result2) {
            cout << num << " ";
        }
        cout << endl;
    }

    if (result3.empty()) {
        cout << "No subarray found." << endl;
    } else {
        for (int num : result3) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}