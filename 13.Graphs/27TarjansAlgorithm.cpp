class Solution {

    /*
    ============================================================
                    BRIDGES IN A GRAPH - DFS
    ============================================================

    WHAT IS A BRIDGE?
    -----------------
    A bridge is an edge which, if removed, disconnects the graph.

    Our goal is to find all such edges without actually removing
    any edge.

    ------------------------------------------------------------
    1. disT[u] - DISCOVERY TIME
    ------------------------------------------------------------
    disT[u] tells us when node u was visited for the first time.

    Example:
    A is visited first  -> disT[A] = 1
    B is visited second -> disT[B] = 2
    C is visited third  -> disT[C] = 3

    A smaller discovery time means an earlier-visited node.

    ------------------------------------------------------------
    2. low[u] - LOWEST (EARLIEST) REACHABLE DISCOVERY TIME
    ------------------------------------------------------------
    low[u] tells us the earliest discovery time that node u's
    DFS subtree can reach.

    Initially:
        low[u] = disT[u]

    Later, low[u] may become smaller if we discover a connection
    to an earlier node.

    Example:
    Suppose disT[A] = 1, disT[B] = 2, disT[C] = 3.

    DFS goes A -> B -> C.

    If C has an extra edge back to A:
        low[C] = 1

    B also learns that its subtree can reach A through C:
        low[B] = min(low[B], low[C])
               = min(2, 1)
               = 1

    IMPORTANT:
    A parent can use information from its child's subtree because
    the child belongs to the parent's DFS subtree.

    ------------------------------------------------------------
    3. WHY ARE THERE TWO DIFFERENT UPDATE CONDITIONS?
    ------------------------------------------------------------

    CASE 1: NEIGHBOR v IS UNVISITED
    --------------------------------
    We explore v completely by calling DFS.

        dfs(v, ...);

    After DFS returns, low[v] contains the earliest discovery
    time reachable through v and its descendants.

    So we update:

        low[u] = min(low[u], low[v]);

    In simple words:
    "My child explored its subtree and found how far back it
    could reach. Let me use that information."

    CASE 2: NEIGHBOR v IS ALREADY VISITED AND IS NOT THE PARENT
    ------------------------------------------------------------
    We do NOT explore v again.

    The edge u-v directly connects u to an already-discovered
    node v, so we use:

        low[u] = min(low[u], disT[v]);

    WHY NOT low[v] HERE?

    Because this edge directly proves that u can reach v.
    Therefore, we use v's discovery time.

    low[v] describes how far v's own DFS subtree can reach.
    That information is not what this direct edge establishes.

    IMPORTANT:
    We ignore the parent because the parent edge is simply the
    edge through which DFS reached u. It is not an alternate path.

    ------------------------------------------------------------
    4. HOW DO WE KNOW IF AN EDGE IS A BRIDGE?
    ------------------------------------------------------------

    Condition:

        if (low[v] > disT[u])

    Here, u is the parent and v is its DFS child.

    Ask yourself:
    "Can v, or anything inside v's subtree, reach u or an
    earlier ancestor without using the edge u-v?"

    CASE A: low[v] > disT[u]
    -----------------------
    The subtree of v cannot reach u or an earlier ancestor
    through a back edge.

    So u-v is the only connection between that subtree and
    the rest of the graph.

    Removing u-v disconnects the graph.
    Therefore, u-v IS A BRIDGE.

    CASE B: low[v] <= disT[u]
    ------------------------
    The subtree of v can reach u or an earlier ancestor
    through another connection.

    Therefore, removing u-v does not disconnect that subtree
    from the rest of the graph.
    So u-v is NOT a bridge.

    ------------------------------------------------------------
    5. COMPLETE ALGORITHM
    ------------------------------------------------------------

    1. Build an adjacency list for the undirected graph.
    2. Start DFS and assign each node a discovery time.
    3. Initially set low[u] = disT[u].
    4. For every neighbor v:

       a. If v is unvisited:
          - Explore v using DFS.
          - Update low[u] using low[v].
          - Check if low[v] > disT[u].
          - If true, store edge u-v as a bridge.

       b. If v is already visited and is not the parent:
          - Update low[u] using disT[v].

    5. Return all the bridges.

    TIME COMPLEXITY: O(V + E)
    SPACE COMPLEXITY: O(V + E)
    where V = number of vertices and E = number of edges.

    NOTE:
    This is the standard parent-vertex implementation for a
    simple undirected graph. If parallel edges are allowed,
    track the parent edge ID instead of just the parent vertex.
    ============================================================
    */

    int time = 1;

    void dfs(int u,
             vector<vector<int>>& adj,
             int p,
             vector<bool>& vis,
             vector<int>& disT,
             vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[u] = true;       // Mark u as visited.

        disT[u] = time;      // Record when u is discovered.
        low[u] = time;       // Initially, u can reach itself.
        time++;

        for (int v : adj[u]) {

            // Ignore the edge back to the parent.
            // It is the same edge through which DFS reached u.
            if (v == p) continue;

            if (!vis[v]) {

                // CASE 1: v is unvisited.
                // Explore v and its entire DFS subtree first.
                dfs(v, adj, u, vis, disT, low, bridges);

                // After DFS returns, low[v] contains information
                // about the earliest node reachable through v's
                // subtree. Pass that information up to u.

                // u dekhta h ki v mera unvisited neighbour h agar v is low time tak phnch skta hai
                // to mai b usi low time pe phnch skta hu
                // toh u apna ow time compare krta hai
                low[u] = min(low[u], low[v]);

                // BRIDGE CONDITION:
                // If v's subtree cannot reach u or an earlier
                // ancestor through a back edge, u-v is a bridge.

                // Mtlb v ka agar low time u ke discovery time se bhi bda hai
                // u aur v mei is edge ke ilava koi link nhi h 
                if (low[v] > disT[u]) {
                    bridges.push_back({u, v});
                }

            } else { 
                // Also bridge cannot be find if its neighbour is visited means if this edge does not even exist v can still be visited
                // So no need to check bridge here

                // CASE 2: v is already visited and is not parent.
                // The direct edge u-v gives a connection to v.
                // Use disT[v], NOT low[v], because we are using
                // this direct edge rather than exploring v's
                // subtree again.
                
                low[u] = min(low[u], disT[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        // Build the adjacency list.
        // The graph is undirected, so add both directions.
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        vector<int> disT(n);
        vector<int> low(n);

        vector<vector<int>> bridges;

        // Start DFS from node 0.
        // Parent is also set to 0 so its initial parent edge
        // is ignored. This works for a simple graph.
        dfs(0, adj, 0, vis, disT, low, bridges);

        return bridges;
    }
};


// Little modification by not using vis vector

class Solution {
    int time=1;
    void dfs(int u, vector<vector<int>>& adj, int p, vector<int>& disT, vector<int>& low, vector<vector<int>>& bridges){

        disT[u] = time;
        low[u] = time;
        time++;

        for(int v: adj[u]){
            if(disT[v]==-1){
                dfs(v, adj, u, disT, low, bridges);

                low[u] = min(low[u], low[v]);

                if(low[v]>disT[u]){
                    bridges.push_back({u,v});
                }
            }
            else if(v!=p){
                low[u] = min(low[u], disT[v]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disT(n,-1);
        vector<int> low(n);

        vector<vector<int>> bridges;

        for(int i=0; i<n; i++){
            if(disT[i]==-1){
                dfs(0, adj, 0, disT, low, bridges);
            }
        }

        return bridges;
    }
};