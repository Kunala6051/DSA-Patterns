#include <bits/stdc++.h>
using namespace std;

/*
Course Schedule (LeetCode 207)

👉 Problem:
Given n courses and prerequisites where [a, b] means you must complete course b before course a,
determine whether it is possible to finish all courses.
Like if [1,0] → you must complete course 0 before course 1
i.e., 0 → 1 (directed edge from 0 to 1), 0 is dependency for 1 [1 depends on 0]

👉 Core Idea:
Treat this as a Directed Graph problem:
- Each course = node
- Each prerequisite [a, b] = edge (b → a)

👉 Key Observation:
- If the graph has a cycle → impossible to complete all courses (return false)
- If no cycle (i.e., DAG) → possible to complete all courses (return true)

👉 Why?
Because a cycle means circular dependency:
A → B → C → A → no starting point

👉 Approach (DFS + Cycle Detection):
We use Depth First Search with two arrays:
1. visited[] → marks nodes that have been visited
2. recursionPath[] → tracks nodes in current DFS path

👉 DFS Logic:
- Mark current node as visited and add it to recursion path
- Traverse all its neighbors:
    • If neighbor not visited → recurse DFS
    • If neighbor is already in recursionPath → cycle detected
- After exploring, remove node from recursionPath (backtracking)

👉 Cycle Detection Condition:
visited[v] == true AND recursionPath[v] == true → cycle exists

👉 Main Function:
- Run DFS for every unvisited node
- If any DFS detects a cycle → return false
- If no cycles found → return true

👉 Complexity:
Time: O(V + E)
Space: O(V)

👉 Summary:
This problem reduces to detecting a cycle in a directed graph.
No cycle = valid course completion
Cycle = impossible to complete courses
*/

/*
Course Schedule using DFS (Cycle Detection)

- helper() detects cycle in directed graph
- vis[] → visited nodes
- recPath[] → nodes in current DFS path (for cycle detection)
*/

bool isCycle(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites){
    vis[src]=true;                // mark current node as visited
    recPath[src]=true;            // add node to current recursion path

    // loop through all edges (prerequisites)
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0]; // course to take
        int v = prerequisites[i][1]; // prerequisite

        // if there is an edge v → u and current node is v
        if(src==v){
            // if neighbor (u) is not visited, do DFS on it
            if(!vis[u]){
                if(isCycle(u, vis, recPath, prerequisites)) return true; // cycle found in deeper call
            } 
            // if neighbor is already in recursion path → cycle detected
            else if(recPath[u]){
                return true;        // back edge → cycle exists
            }
        }
    }

    recPath[src] = false;         // remove node from recursion path (backtracking)
    return false;                 // no cycle found from this node
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
    vector<bool> vis(numCourses, false);      // visited array
    vector<bool> recPath(numCourses, false);  // recursion path array

    // try DFS from every node (important for disconnected graph)
    for(int i=0; i<numCourses; i++){
        if(!vis[i]){                          // if node not visited
            if(isCycle(i, vis, recPath, prerequisites)) 
                return false;                 // cycle found → cannot finish courses
        }
    }

    return true;                              // no cycle → all courses can be completed
}

// LeetCode 210 - Course Schedule II

/*
Course Schedule II (Topological Sort using DFS)

- First we ensure no cycle exists (using canFinish)
- Then we perform DFS-based topological sorting
- Stack stores nodes in reverse topological order
*/

void dfs(int src, vector<bool>& vis, stack<int>& topSort, vector<vector<int>>& prerequisites){

    vis[src] = true;                 // mark current node as visited

    // traverse all edges to find neighbors of src
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0]; // course to take
        int v = prerequisites[i][1]; // prerequisite

        // if there is an edge v → u and current node is v
        if(v==src){
            // if neighbor not visited, visit it
            if(!vis[u]){
                dfs(u, vis, topSort, prerequisites); // recursive DFS call
            }
        }
    }

    // after visiting all neighbors, push current node into stack
    // ensures correct topological order (post-order insertion)
    topSort.push(src);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;                  // final topological order

        // if cycle exists → no valid ordering
        if(!canFinish(numCourses, prerequisites)) return result;

        vector<bool> vis(numCourses, false); // visited array
        stack<int> topSort;                  // stack for topo sort

        // run DFS for all nodes (handles disconnected graph)
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){                    // if node not visited
                dfs(i, vis, topSort, prerequisites);
            }
        }

        // stack has reverse order → pop to get correct order
        while(!topSort.empty()){
            result.push_back(topSort.top());
            topSort.pop();
        }

        return result; // return valid course order
}

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}}; // cycle exists: 0 → 1 → 0
    cout << canFinish(numCourses, prerequisites) << endl; // Output: 0 (false)
    vector<int> order = findOrder(numCourses, prerequisites);
    if(order.empty()){
        cout << "No valid course order (cycle detected)" << endl;
    } else {
        cout << "Course order: ";
        for(int course : order){
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}