#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// Undirected Graph Cycle :
     // 1. DFS
     // 2. BFS
     // 3. Union-Find (Disjoint Set Union)

// Directed Graph Cycle :
     // 1. DFS
     // 2. BFS
     // 3. Kahn's Algorithm (Topological Sort)

/*
Approach: Detect Cycle in an Undirected Graph using DFS

Idea:
-----
In an undirected graph, while performing DFS traversal, every node can have
multiple neighbors. Normally, when we move from node A to node B, B will have A
as one of its neighbors. Since A is already visited, we must ignore this edge
because it simply leads back to the parent.

Therefore, to correctly detect cycles we must track the "parent" node.

Key Observation:
----------------
If during DFS we encounter a neighbor that is already visited AND that neighbor
is NOT the parent of the current node, then a cycle exists.

Why?
Because it means there exists another path that reaches the same node,
forming a loop in the graph.

Example:
--------

    0
   / \
  1---2

DFS Traversal:
0 -> 1 -> 2

When we reach node 2:
Neighbors = {1, 0}

1 is the parent → ignore
0 is already visited AND not the parent → cycle detected

Algorithm Steps:
----------------
1. Maintain a visited array to track visited nodes.
2. Start DFS from each unvisited node (important for disconnected graphs).
3. During DFS:
      mark current node as visited.
4. For each neighbor of the current node:
      Case 1: Neighbor not visited
              → recursively call DFS(neighbor, current_node)

      Case 2: Neighbor already visited 
              → if neighbor != parent  (this is known as a BACK EDGE)
                    cycle detected

5. If any recursive call detects a cycle → return true.
6. If traversal completes without detecting a cycle → return false.

Handling Disconnected Graph:
----------------------------
The graph may contain multiple components, so we must run DFS
for every unvisited vertex.

Time Complexity:
----------------
O(V + E)

Where:
V = number of vertices
E = number of edges

Each vertex and edge is processed at most once.

Space Complexity:
-----------------
O(V)

Used for:
- visited array
- recursion stack
*/


class Graph{
    int v;
    list<int> *arr; // array of lists to represent the graph

public:
    Graph(int ver){
        v=ver;
        arr=new list<int>[v]; // create an array of lists with size equal to the number of vertices
    }

    void addEdge(int n, int m){ // undirected graph (both n and m are connected)
        arr[n].push_back(m);
        arr[m].push_back(n);
        // for directed graph, only arr[n].push_back(m) is needed
    }

    bool helper(int r, vector<bool>& vis, int parent){
        vis[r] = true;
        for(int i: arr[r]){
            if(!vis[i]){
                helper(i, vis, r);
            } else{
                if(i!=parent) return true;
            }
        }
        return false;
    }

    bool detectCycle(){ 
        vector<bool> vis(v, false);
        // Since the graph can be disconnected, we need to check for cycles in all components of the graph.
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(helper(i, vis, -1)) return true;
            }
        }
        return false;
    }
    // Time Complexity: O(V + E) 
    //      where V is the number of vertices and E is the number of edges in the, since we are visiting each vertex and edge at most once.

    bool helper2(int r, vector<bool>& vis){
        queue<pair<int, int>> q;
        q.push({r, -1});
        vis[r]=true;
        while(!q.empty()){
            int f = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int i: arr[f]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push({i, f});
                } else{
                    if(i!=par) return true;
                }
            }
        }
        return false;
    }

    bool detectCycleBFS(){
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(helper2(i, vis)) return true;
            }
        }
        return false;
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

    if(g.detectCycle()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;

    if(g.detectCycleBFS()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;

    // Connected Graph

    Graph g2(6); // create a graph with 6 vertices (0 to 5)
    // Adding edges to the graph. The graph structure will be:  
    //             0
    //           /   \
    //          1-----2
    //        / | \
    //       3  4  5

    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(1,3);
    g2.addEdge(1,4);
    g2.addEdge(1,5);

    if(g2.detectCycle()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;

    if(g2.detectCycleBFS()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;



    return 0;
}