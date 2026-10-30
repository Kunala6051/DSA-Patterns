#include <bits/stdc++.h>
using namespace std;


/*
APPROACH (Topological Sort using DFS)

Topological sorting is used for Directed Acyclic Graphs (DAG). It gives an ordering
of vertices such that for every directed edge (u -> v), vertex u appears before v
in the ordering.

Algorithm Steps:
1. Represent the graph using an adjacency list.
2. Maintain a visited array to track which nodes have already been processed.
3. For every unvisited vertex, run DFS.
4. During DFS:
      - Mark the current node as visited.
      - Recursively visit all its unvisited neighbors.
      - After visiting all neighbors, push the current node into a stack.
5. After DFS completes for all vertices, pop elements from the stack.
   The popping order gives the topological ordering.

Why it works:
A node is pushed into the stack only after all nodes reachable from it
are processed. Therefore dependencies appear before the node in the stack.

Time Complexity:  O(V + E)
Space Complexity: O(V)
*/


// Basically, we will store our topological order in reverse order in a stack.
// So, firstly we will perform DFS and after visiting all neighbors of a node, we will push it into the stack.
// Finally, we will push the current node into the stack and then pop all elements from the stack to get the topological order.

class Graph{
    int v;
    list<int> *arr; // adjacency list representation of graph

public:

    // constructor to initialize graph with v vertices
    Graph(int ver){
        v = ver;
        arr = new list<int>[v]; // create array of lists for adjacency list
    }

    // function to add a directed edge from n -> m
    void addEdge(int n, int m){
        arr[n].push_back(m); // add m in adjacency list of n
    }

    // DFS function used to explore graph and build stack order
    void dfs(int curr, vector<bool>& vis, stack<int>& topSort){

        vis[curr] = true; // mark current node as visited

        // traverse all neighbors of current node
        for(int neigh : arr[curr]){

            // if neighbor is not visited, explore it
            if(!vis[neigh]){
                dfs(neigh, vis, topSort);
            }
        }

        // after visiting all neighbors, push current node into stack
        // this ensures nodes with no outgoing edges come first in result
        topSort.push(curr);
    }

    // function to perform topological sorting
    vector<int> topologicalSort(){

        vector<bool> vis(v, false); // visited array
        stack<int> topSort;         // stack to store ordering

        // run DFS for every vertex (handles disconnected components)
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfs(i, vis, topSort);
            }
        }

        // pop elements from stack to get topological order
        vector<int> result;

        while(!topSort.empty()){
            result.push_back(topSort.top());
            topSort.pop();
        }

        return result; // return final topological ordering
    }
};

int main(){
    Graph g(6); // create a graph with 6 vertices (0 to 5)
    // Adding edges to the graph. The graph structure will be:
    //             0
    //           /   \
    //          1     2
    //        / | \
    //       3  4  5
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);

    vector<int> topoSort = g.topologicalSort();
    cout << "Topological Sort: ";
    for(int i: topoSort){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


