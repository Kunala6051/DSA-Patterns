#include <iostream>
#include <vector>

using namespace std;

// Leetcode 134
// Gas Station

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
// You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, 
// return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. 
// If there exists a solution, it is guaranteed to be unique.

/*
Approach:
-----------
1. First, check if the total gas available is less than the total cost required.
   - If yes, the journey is impossible → return -1.

2. If the total gas is sufficient:
   - Traverse each station and track `currGas`, the remaining fuel after visiting each station.
   - At each step, add the gas gained and subtract the cost to reach the next station.
   - If `currGas` becomes negative, it means we can’t start from any station before this one.
     → So, we reset `currGas = 0` and set the next station as the new starting point.

3. The final `ans` will be the index of the station from where the circuit can be completed.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;

    // Step 1: Calculate total gas and total cost
    for (int i = 0; i < cost.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }

    // If total gas < total cost, journey is impossible
    if (totalGas < totalCost) return -1;

    int ans = 0, currGas = 0;

    // Step 2: Try to find a valid starting point
    for (int i = 0; i < gas.size(); i++) {
        currGas = currGas + gas[i] - cost[i];  // net gas after visiting station i

        if (currGas < 0) {                     // can't reach next station
            if (i == (cost.size() - 1)) ans = i;  // edge case: last station
            else ans = i + 1;                     // try next station as start
            currGas = 0;                          // reset current gas
        }
    }

    return ans;  // return starting station index
}

// O(N) time complexity, O(1) space complexity


int main() {
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Starting gas station index: " << canCompleteCircuit(gas1, cost1) << endl; // Output: 3

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Starting gas station index: " << canCompleteCircuit(gas2, cost2) << endl; // Output: -1

    return 0;
}