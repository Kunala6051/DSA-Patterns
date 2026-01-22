#include <bits/stdc++.h>
using namespace std;

// Leetcode: 901. Online Stock Span

// Time Complexity: O(n)
// Space Complexity: O(n)


int main() {
    // Stock prices for consecutive days
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // 'ans' stores span for each day (result)
    vector<int> ans(price.size(), 0);

    // Stack to keep track of previous higher prices' indices
    stack<int> s;

    // Iterate through all days
    for (int i = 0; i < price.size(); i++) {

        // Pop all smaller or equal prices from stack
        while (s.size() > 0 && price[s.top()] <= price[i]) {
            s.pop();
        }

        // If stack is empty, it means no higher price on left → span = i + 1
        if (s.empty()) {
            ans[i] = i + 1;
        } 
        // Else, span = current index - previous higher price index
        else {
            ans[i] = i - s.top();
        }

        // Push current index onto stack
        s.push(i);
    }

    // Print all span values
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
