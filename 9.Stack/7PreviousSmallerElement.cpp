#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmaller(vector <int> nums){
    stack<int>s;
    vector<int>ans;

    for(int i=0; i<nums.size(); i++){
        while(s.size()>0 && s.top()>=nums[i]) s.pop();
        if(s.size()==0) ans.push_back(-1);
        else ans.push_back(s.top());
        s.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 1, 0, 8, 6}; 

    vector<int> result = previousSmaller(nums);

    // Print the results
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
