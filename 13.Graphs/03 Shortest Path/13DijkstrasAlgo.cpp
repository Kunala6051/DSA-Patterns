#include <bits/stdc++.h>
using namespace std;

/*
    Priority queue (Max heap) is the data structure in which the element with the highest priority is served first. 
    In case of a tie, the element that was added to the queue first is served first.

    There is another form of priority queue called min heap, where the element with the lowest priority is served first.

    It is declared as priority_queue<type> pq; where type is the data type of the elements in the queue.

    eg. priority_queue<int> pq; // max heap of integers
    eg. priority_queue<int, vector<int>, greater<int>> pq; // min heap of integers

    If we want to store pairs in the priority queue, we can use the following syntax:
    priority_queue<pair<int, int>> pq; // max heap of pairs (first element is the priority)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap of pairs

*/

// Dijkstra's Algorithm is a popular algorithm used to find the shortest paths from a source vertex to 
// all other vertices in a graph with non-negative edge weights. 
// It is a greedy algorithm that works by iteratively selecting the vertex with the smallest distance from the source
// and updating the distances of its neighbors. The algorithm continues until all vertices have been processed.

class Edge{
public:
    int v, wt;
    Edge(int v, int weight) : v(v), wt(weight) {}
};

vector<int> shortestPaths(int src, vector<vector<Edge>> g, int V){
    vector<int> dist(V, INT_MAX);
    dist[src]=0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0,src});

    while(!q.empty()){
        int u = q.top().second;
        q.pop();

        for(Edge e: g[u]){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                q.push({dist[e.v], e.v});
            }
        }
    }
    return dist;
}

int main(){
    int v=6;
    vector<vector<Edge>> g(v);
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));
    g[3].push_back(Edge(5, 1));
    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    // The graph structure is as follows:
    //         2
    //    0 --------> 1
    //    |           |\
    //    |4          | \7
    //    |           |  \
    //    v           v   v
    //    2 -------> 4 -->3
    //       3        |    |
    //                |2   |1
    //                |    |
    //                v    v
    //                3 -->5
    // Also

    // 4 ----5----> 5
    
    vector<int> dist = shortestPaths(0, g, v);
    cout << "Shortest distances from source 0: ";
    for(int i=0; i<v; i++){
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
    return 0;
}