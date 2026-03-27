#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/*
Approach (Kahn's Algorithm for Topological Sorting):

1. Compute indegree of each vertex:
   - indegree[i] = number of incoming edges to node i

2. Push all vertices with indegree = 0 into a queue:
   - These nodes have no dependencies, so they can appear first

3. Process the queue:
   - Remove a node from queue
   - Add it to result (topological order)
   - For all its neighbors:
        → Reduce their indegree by 1
        → If indegree becomes 0, push into queue

4. Continue until queue is empty

5. The result vector contains topological ordering of the graph
*/

class Graph{
    int v;
    list<int> *arr; // array of lists to represent the graph

public:
    Graph(int ver){
        v=ver;
        arr=new list<int>[v]; // create an array of lists with size equal to the number of vertices
    }

    void addEdge(int n, int m){ 
        arr[n].push_back(m);
        // for directed graph, only arr[n].push_back(m) is needed
    }

    
    vector<int> khanTop(){
        vector<int> res;                  // stores final topological order
        
        vector<int> indegree(v, 0);       // indegree array initialized to 0
        
        // Step 1: Calculate indegree of each vertex
        for(int i=0; i<v; i++){
            for(int j: arr[i]){           // for all neighbors of node i
                indegree[j]++;            // increase indegree of neighbor
            }
        }

        queue<int> q;                     // queue to process nodes with indegree 0

        // Step 2: Push all nodes with indegree 0 into queue
        for(int i=0; i<v; i++){
            if(indegree[i]==0) 
                q.push(i);                // node has no incoming edges
        }

        // Step 3: Process nodes using BFS-like approach
        while(!q.empty()){
            int f = q.front();            // get front node
            q.pop();                      // remove it from queue

            res.push_back(f);             // add to topological order

            // Step 4: Reduce indegree of neighbors
            for(int j: arr[f]){
                indegree[j]--;            // remove edge f → j

                // if indegree becomes 0, push into queue
                if(indegree[j]==0) 
                    q.push(j);
            }
        }

        // Step 5: return result
        return res;
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

    vector<int> topoSort = g.khanTop();
    cout << "Topological Sort: ";
    for(int i: topoSort){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

