#include <bits/stdc++.h>
using namespace std;


/*
============================================================
              ARTICULATION POINT IN A GRAPH
============================================================

1. WHAT IS AN ARTICULATION POINT?
---------------------------------
An articulation point is a node whose removal disconnects
the graph into more connected parts.

Example:
    A --- B --- C

If we remove B, A and C become disconnected.
So, B is an articulation point.

Our goal is to find all such nodes using DFS.

------------------------------------------------------------
2. WHAT ARE disT[] AND low[]?
------------------------------------------------------------

A) disT[u] - DISCOVERY TIME

It tells us when node u was visited for the first time.

Example:
    A visited first  -> disT[A] = 1
    B visited second -> disT[B] = 2
    C visited third  -> disT[C] = 3

Smaller discovery time means an earlier-visited node.

B) low[u] - LOWEST REACHABLE DISCOVERY TIME

It tells us the earliest discovery time that node u's
DFS subtree can reach using DFS tree edges and back edges.

Initially:
    disT[u] = time
    low[u]  = time

Later, low[u] may become smaller if we find a connection
to an earlier node.

Example:
    DFS goes A -> B -> C

If C has an extra edge back to A:
    disT[A] = 1
    disT[B] = 2
    disT[C] = 3

    low[C] = 1

C can reach A directly through the extra edge.

B also learns that its subtree can reach A through C:
    low[B] = min(low[B], low[C])
           = min(2, 1)
           = 1

Remember:
A parent can use information from its child's subtree
because the child is part of that subtree.

------------------------------------------------------------
3. MAIN DFS APPROACH
------------------------------------------------------------

Step 1:
Start DFS from a node.

Step 2:
Mark the node as visited and assign its discovery time.

Step 3:
Initially set low[u] = disT[u], because the node can
always reach itself.

Step 4:
Visit every neighbor v of u.

There are three important situations:

------------------------------------------------------------
CASE 1: v IS NOT VISITED
------------------------------------------------------------

This means we have found a new DFS child.

First, explore that child completely:

    dfs(v, u);

After DFS returns, update:

    low[u] = min(low[u], low[v]);

WHY low[v]?

Because v's entire subtree has now been explored.
It may have found a back edge to an earlier node.

If v can reach an earlier node, u's subtree can also
reach that node through v.

So u updates its low value using the child's information.

------------------------------------------------------------
CASE 2: v IS ALREADY VISITED AND IS NOT THE PARENT
------------------------------------------------------------

This means we have found a back edge to an already-visited
node, rather than a new DFS child.

Update:

    low[u] = min(low[u], disT[v]);

WHY disT[v], NOT low[v]?

Because this direct edge connects u to v.

It proves that u can reach v, so we use v's discovery time.

low[v] describes how far v's own subtree can reach.
We do not use that value for this direct back-edge update.

In simple words:
Unvisited neighbor -> explore it and use low[v].
Visited non-parent neighbor -> use disT[v].

------------------------------------------------------------
4. HOW TO IDENTIFY AN ARTICULATION POINT?
------------------------------------------------------------

There are TWO rules.

RULE 1: FOR A NORMAL NODE (NOT THE ROOT)
----------------------------------------

Condition:

    if (parent != -1 && low[v] >= disT[u])

Here:
- u is the current node.
- v is an unvisited DFS child of u.
- parent != -1 means u is not the root.

WHY low[v] >= disT[u]?

It means the subtree of v cannot reach an ancestor of u
through a back edge.

The subtree depends on u to stay connected to the
earlier part of the graph.

If we remove u, that child's subtree becomes disconnected
from the earlier part of the graph.

Therefore, u is an articulation point.

WHY >= AND NOT JUST > ?

If low[v] > disT[u]:
    The subtree cannot reach u or an earlier ancestor
    through a back edge.

If low[v] == disT[u]:
    The subtree can reach u, but cannot reach an ancestor
    above u through a back edge.

In both cases, removing u disconnects the subtree from
the earlier part of the graph.

That is why we use >=.

IMPORTANT:
If the condition is true for even one DFS child of a
normal node u, u is an articulation point.

------------------------------------------------------------
RULE 2: FOR THE ROOT NODE
------------------------------------------------------------

The root is the starting node of the DFS tree.
Its parent is -1.

The normal condition cannot be applied to the root.

Why?

A normal node can have an ancestor above it.
The root has no parent and no ancestor above it.

So we use a separate rule:

    if (parent == -1 && childCount > 1)

The root is an articulation point only if it has MORE
THAN ONE DFS CHILD.

Why?

If the root has two or more DFS children, their subtrees
are separate branches of the DFS tree.

Removing the root disconnects those branches from
each other.

If the root has only one DFS child, removing it does
not split its DFS tree into multiple child subtrees.

IMPORTANT:
childCount means the number of DFS tree children,
NOT the total number of neighbors.

Only increment childCount when an unvisited neighbor
is found.

------------------------------------------------------------
5. COMPLETE FLOW OF THE ALGORITHM
------------------------------------------------------------

1. Build the adjacency list for the undirected graph.

2. Create:
       vis[]     -> tracks visited nodes
       disT[]    -> discovery time of each node
       low[]     -> earliest reachable discovery time
       isAP[]    -> marks articulation points

3. Start DFS.

4. For every node u:
   - Mark it visited.
   - Set disT[u] and low[u].
   - Set childCount = 0.

5. For every neighbor v:
   - If v is unvisited:
       Increment childCount.
       Run DFS on v.
       Update low[u] using low[v].
       If u is not the root and
       low[v] >= disT[u], mark u as an articulation point.

   - Else if v is not the parent:
       Update low[u] using disT[v].

6. After processing all neighbors:
   - If u is the root and childCount > 1,
     mark u as an articulation point.

7. Collect all marked nodes and return them.

NOTE:
If the graph may be disconnected, start DFS from every
unvisited node, not just node 0.

------------------------------------------------------------
6. TIME AND SPACE COMPLEXITY
------------------------------------------------------------

Time Complexity: O(V + E)
Every vertex and edge is processed a constant number of
times.

Space Complexity: O(V + E)
The adjacency list takes O(V + E) space.
The visited, discovery, low, and articulation arrays
take O(V) space.
The DFS recursion stack can take O(V) space.

------------------------------------------------------------
7. QUICK REVISION - REMEMBER THESE LINES
------------------------------------------------------------

low[u] = min(low[u], low[v]);

Child was explored. Use its subtree information.

low[u] = min(low[u], disT[v]);

Already-visited non-parent neighbor. Use its discovery time.

low[v] >= disT[u];

For a normal node, this condition means u is an
articulation point.

parent == -1 && childCount > 1;

For the root, more than one DFS child means it is an
articulation point.

FINAL MEMORY TRICK:
Normal node -> check low[v] >= disT[u].
Root node   -> check childCount > 1.
============================================================
*/

int Time = 1;

void dfs(int u, vector<vector<int>>& adj, int parU,
         vector<int>& dt, vector<int>& low, unordered_set<int>& s) {

    dt[u] = Time;       // Node visit hone ka time
    low[u] = Time;      // Initially, low = discovery time
    Time++;

    int unVisChild = 0; // DFS tree ke children count

    for (int v : adj[u]) {

        if (dt[v] == -1) {  // Agar v unvisited hai
            unVisChild++;

            dfs(v, adj, u, dt, low, s); // Pehle child explore karo

            // Child ki help se earliest reachable time update karo
            low[u] = min(low[u], low[v]);

            // Root nahi hai aur child u ke ancestor tak nahi pahunch sakta
            if (parU != -1 && low[v] >= dt[u]) {
                s.insert(u); // u articulation point hai
            }
        }
        else if (v != parU) { // Visited hai, but parent nahi hai

            // Back edge se reachable discovery time update karo
            low[u] = min(low[u], dt[v]);
        }
    }

    // Root ke liye special condition
    if (parU == -1 && unVisChild > 1) {
        s.insert(u); // Multiple DFS children => articulation point
    }
}

vector<int> articulationPoints(vector<vector<int>>& adj) {

    int v = adj.size();

    vector<int> dt(v, -1); // -1 means unvisited
    vector<int> low(v);

    vector<int> res;
    unordered_set<int> s; // Duplicate articulation points nahi honge

    Time = 1; // Timer reset karo

    for (int i = 0; i < v; i++) {
        if (dt[i] == -1) {
            dfs(i, adj, -1, dt, low, s); // Har component ke liye DFS
        }
    }

    for (int i : s) {
        res.push_back(i); // Set se result mein copy karo
    }

    return res;
}

int main() {
    vector<vector<int>> adj(6);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[4].push_back(3);
    adj[3].push_back(4);

    vector<int> res = articulationPoints(adj);

    for (int i : res) cout << i << " ";
}