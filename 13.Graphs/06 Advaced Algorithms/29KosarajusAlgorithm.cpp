#include <bits/stdc++.h>
using namespace std;

/*
========================================================
              KOSARAJU'S ALGORITHM
========================================================

1. WHAT IS AN SCC?
------------------
SCC = Strongly Connected Component.

In a directed graph, every node in an SCC can reach
every other node in that same SCC.

A single node can also be an SCC.

--------------------------------------------------------
2. THE MAIN IDEA: IMAGINE EACH SCC AS ONE NODE
--------------------------------------------------------

Imagine our graph has 3 SCCs: A, B and C.

    A -----> B -----> C

Here, A, B and C represent complete SCCs, not
individual vertices.

WHY CAN'T THERE BE A CYCLE BETWEEN THESE SCCs?

Suppose A can reach B, and B can also reach A.
Then every node in A and B can reach the other group.

So A and B would actually be ONE SCC, not two separate
SCCs.

Therefore, if we treat every SCC as one node, the
resulting graph is always a DAG
(Directed Acyclic Graph).

THIS IS THE MAIN LOGIC BEHIND KOSARAJU'S ALGORITHM.

--------------------------------------------------------
3. STEP 1: DFS AND PUSH NODES INTO A STACK
--------------------------------------------------------

Run DFS on the ORIGINAL graph.

Push a node into the stack only AFTER exploring all
its unvisited neighbors.

    dfs(v, ...);
    s.push(u);

WHY?

Nodes that finish later are placed closer to the
TOP of the stack.

This finishing-time order helps us process the SCCs
in the correct order during the second DFS.

NOTE:
The original graph may contain cycles, so this is
not necessarily a topological sort of the original
graph. It is a finishing-time order.

--------------------------------------------------------
4. STEP 2: REVERSE ALL THE EDGES
--------------------------------------------------------

If the original graph has:

    A -> B

The reversed graph has:

    A <- B

WHY DO WE NEED THIS?

Look at our simplified DAG:

    A -> B -> C

Without reversing the edges, DFS starting at A could
travel into B and C, mixing separate SCCs.

After reversing:

    A <- B <- C

Now, starting DFS from A cannot travel to B or C.

So A can be collected separately.

After that, we process B and C in stack order.

IMPORTANT:
Reversing the graph alone is NOT enough.
The stack order and reversed graph work TOGETHER.

--------------------------------------------------------
5. STEP 3: POP AND DFS ON THE REVERSED GRAPH
--------------------------------------------------------

Pop the top node from the stack.

If it is already visited, skip it.

Otherwise:
    - Start DFS on the REVERSED graph.
    - Collect every node reached by this DFS.
    - Store these nodes as one SCC.

WHY DOES THIS WORK?

The stack order makes us process SCCs in a safe order.

Reversing the edges prevents DFS from moving outward
into SCCs that have not yet been processed.

Therefore, each new DFS collects one SCC.

--------------------------------------------------------
6. WHY TWO VISITED ARRAYS?
--------------------------------------------------------

vis  -> Used during DFS on the original graph.
vis2 -> Used during DFS on the reversed graph.

The second DFS is a fresh traversal, so we need a
fresh visited array.

--------------------------------------------------------
7. COMPLETE APPROACH
--------------------------------------------------------

1. Run DFS on the original graph and push each node
   after exploring its neighbors.

2. Reverse every edge to create the transpose graph.

3. Pop nodes from the stack.

4. For every unvisited popped node, run DFS on the
   transpose graph and collect one SCC.

5. Store each SCC in the answer.

--------------------------------------------------------
8. COMPLEXITY
--------------------------------------------------------

Time:  O(V + E)
Space: O(V + E)

========================================================
*/

// STEP 1: DFS on original graph
void dfs(int i, vector<vector<int>>& adj,
         vector<bool>& vis, stack<int>& s) {

    vis[i] = true; // Mark node visited

    for (int v : adj[i]) {
        if (!vis[v]) {
            dfs(v, adj, vis, s); // Explore neighbor first
        }
    }

    s.push(i); // Push after DFS finishes for this node
}

// STEP 3: DFS on reversed graph
void dfs2(int i, vector<vector<int>>& adj,
          vector<bool>& vis, vector<int>& t) {

    vis[i] = true; // Mark node visited
    t.push_back(i); // Add node to current SCC

    for (int v : adj[i]) {
        if (!vis[v]) {
            dfs2(v, adj, vis, t); // Explore SCC neighbors
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(
    vector<vector<int>>& adj) {

    int v = adj.size();

    stack<int> s;
    vector<bool> vis(v, false);

    // STEP 1: Get nodes in finishing-time order
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, s);
        }
    }

    vector<bool> vis2(v, false); // Fresh visited array
    vector<vector<int>> res; // Stores all SCCs

    // STEP 2: Create the reversed graph
    vector<vector<int>> adj2(v);

    for (int u = 0; u < v; u++) {
        for (int v : adj[u]) {
            adj2[v].push_back(u); // Reverse u -> v into v -> u
        }
    }

    // STEP 3: Process nodes by finishing-time order
    while (!s.empty()) {
        int u = s.top();
        s.pop(); // Take the node with latest finishing time

        if (!vis2[u]) {
            vector<int> temp; // Current SCC

            dfs2(u, adj2, vis2, temp); // Find this SCC

            res.push_back(temp); // Save the SCC
        }
    }

    return res;
}

// Complexity:
// Time:  O(V + E)
// Space: O(V + E)

int main() {
    vector<vector<int>> adj(5);

    adj[0].push_back(2); // 0 -> 2
    adj[0].push_back(3); // 0 -> 3

    adj[2].push_back(1); // 2 -> 1
    adj[1].push_back(0); // 1 -> 0

    adj[3].push_back(4); // 3 -> 4

    vector<vector<int>> res = stronglyConnectedComponents(adj);

    for (vector<int> component : res) {
        for (int i : component) {
            cout << i << " ";
        }
        cout << endl; // Next SCC on a new line
    }
}