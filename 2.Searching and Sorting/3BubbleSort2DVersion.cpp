// 📝 Problem Statement

// You are given a list of nodes of a binary tree stored as:

// [ value, row, column ]

// Each element represents:

// value → node value
// row → depth of node
// column → horizontal position
// 🔹 Task

// Sort the list such that:

// Nodes are sorted by column (ascending)
// If columns are equal → sort by row (ascending)
// If both column and row are equal → sort by value (ascending)
// 🔹 Constraint
// ❌ You are not allowed to use built-in sorting functions
// ✅ You must implement sorting manually (e.g., bubble sort, merge sort)
// 🔹 Input Example
// [
//   [3, 0, 0],
//   [9, 1, -1],
//   [20, 1, 1],
//   [15, 2, 0],
//   [7, 2, 2]
// ]
// 🔹 Expected Output
// [
//   [9, 1, -1],
//   [3, 0, 0],
//   [15, 2, 0],
//   [20, 1, 1],
//   [7, 2, 2]
// ]

void bubbleSort2D(vector<vector<int>>& temp) {
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp.size() - i - 1; j++){
            
            vector<int> &a = temp[j];
            vector<int> &b = temp[j+1];

            if(
                (a[2] > b[2]) ||                                   // col
                (a[2] == b[2] && a[1] > b[1]) ||                   // row
                (a[2] == b[2] && a[1] == b[1] && a[0] > b[0])      // value
            ){
                swap(temp[j], temp[j+1]);
            }
        }
    }

}