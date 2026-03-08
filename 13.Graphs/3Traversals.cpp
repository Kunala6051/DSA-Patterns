#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

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

    void printGraph(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(int j:arr[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void BFStraversal(int r=0){ // Default starting vertex is 0
        vector<bool> visited(v, false);
        queue<int> q;
        q.push(r);
        visited[r] = true; // Mark the starting vertex as visited
        while(!q.empty()){
            int a = q.front();
            q.pop();
            cout << a << " ";
            for(int i: arr[a]){
                if(!visited[i]){ 
                    visited[i] = true; // Mark as visited when enqueuing to avoid multiple enqueues of the same vertex
                    q.push(i);
                }
            }
        }
        cout << endl;

    }

    void helper(int r, vector<bool>& vis){
        vis[r] = true;
        cout << r << " ";
        for(int i: arr[r]){
            if(!vis[i]){
                helper(i, vis);
            }
        }
    }

    void DFStraversal(int r=0){ // Default starting vertex is 0
        vector<bool> vis(v, false);
        helper(r, vis);
        cout << endl;
    }

    // In case the graph is disconnected, we can call DFStraversal for all vertices to ensure all components are covered
    void DFSforALL(){
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                helper(i, vis); // This will perform DFS for the current component and mark all its vertices as visited
                // After this call, all vertices in the current component will be marked as visited, 
                // so the next iterations will skip them until it finds an unvisited vertex which belongs to another component. 
                // This way we ensure that all disconnected components of the graph are also traversed.
            }
        }
    }
};

// Time Complexity: O(V + E) 
//      where V is the number of vertices and E is the number of edges in the graph.

// Space Complexity: O(V) for the visited array and O(V) for the queue in BFS, 
//      and O(V) for the recursion stack in DFS.

int main(){
    Graph g(10); // create a graph with 6 vertices (0 to 5)
    // Adding edges to the graph. 
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(7,8);
    g.addEdge(7,9);

    // The graph structure will be:
    //             0
    //           / | \
    //          1  2  3
    //        /  \  
    //       4    5 
    //           / \
    //          6   7
    //             / \
    //            8   9

    // Perform BFS traversal starting from vertex 5
    // Tree structure for BFS starting from vertex 5:
    //               5
    //            /  |  \
    //          1    6   7
    //        /  \       / \
    //       0    4     8   9
    //      / \
    //     2   3

    cout << "BFS Traversal starting from vertex 5: ";
    g.BFStraversal(5); // Should print values in BFS order starting from vertex 5: 5 1 6 7 0 4 8 9 2 3
    
    cout << "DFS Traversal starting from vertex 5: ";
    g.DFStraversal(5); 

    return 0;
}