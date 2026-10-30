#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
    int v;

    // array of lists to represent the graph, where each index represents a vertex and the list at that index contains the adjacent vertices
    // Using a list allows for efficient insertion of edges and dynamic resizing as the number of edges can vary for each vertex
    // Using dynamic allocation (new) allows us to create an array of lists based on the number of vertices specified at runtime
    
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

    g.printGraph();

    return 0;
}