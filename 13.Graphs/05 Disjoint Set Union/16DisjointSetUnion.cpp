#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
                    DISJOINT SET UNION (DSU) / UNION-FIND
===============================================================================

Definition:
-----------
DSU is a data structure used to maintain and track a collection of
non-overlapping (disjoint) sets.

Alternative Name:
-----------------
Disjoint Set Union (DSU) = Union Find


Applications:
-------------
1. Kruskal's Algorithm
2. Cycle Detection in Undirected Graphs
3. Dynamic Connectivity Problems
4. Grouping/Clustering Problems


===============================================================================
Core Idea
===============================================================================

Each element belongs to exactly one set.

Initially:
Every element forms its own set.

Example:

0   1   2   3   4

{0} {1} {2} {3} {4}


Union(0,1)

Sets become:

{0,1} {2} {3} {4}


Union(1,2)

Sets become:

{0,1,2} {3} {4}


Find(x):
Returns the representative (leader/root) of x's set.


===============================================================================
DSU Operations
===============================================================================

1) Find(x)
-----------
Returns the ultimate parent (leader) of x.

Example: 0->2->3->4
Find(4) returns 0
Find(3) returns 0
Find(2) returns 0
Find(0) returns 0


2) Union(a,b)
--------------
Merges the sets containing a and b.


===============================================================================
Data Structures Used
===============================================================================

parent[i]
----------
Stores the immediate parent of i.

Example: 0->2->3->4
parent[2] = 0
parent[3] = 2
parent[4] = 3


rank[i]
--------
Stores the approximate height of the tree.
Used to optimize union operations by attaching smaller tree under larger tree.

Example: 0->2->3->4
rank[0] = 3 (height of tree rooted at 0)
rank[2] = 2 (height of tree rooted at 2)
rank[3] = 1 (height of tree rooted at 3)
rank[4] = 0 (height of tree rooted at 4)


Initialization
--------------

for(i=0;i<n;i++)
{
    parent[i]=i;
    rank[i]=0;
}


Initially:

parent = [0,1,2,3,4]
rank   = [0,0,0,0,0]


===============================================================================
Find Operation
===============================================================================

Goal:
-----
Find the topmost leader.


Recursive Implementation:

int find(int x)
{
    if(parent[x]==x)
        return x;

    return find(parent[x]);
}


Example:


0
|
2
|
3
|
4


find(4)

4 -> 3 -> 2 -> 0

Answer = 0


===============================================================================
Path Compression (Optimization)
===============================================================================

Optimized Find:


int find(int x)
{
    if(parent[x]!=x)
        parent[x]=find(parent[x]);

    return parent[x];
}


Benefit:
--------
Flattens the tree.

Future find operations become very fast.


===============================================================================
Union By Rank
===============================================================================

Idea:
-----
Always attach the smaller-height tree under the larger-height tree.


Step 1:
-------
Find leaders.


pa = find(a);
pb = find(b);


Step 2:
-------
If already in same set:

if(pa==pb)
    return;


Step 3:
-------
Compare ranks.


Case 1:
-------
rank[pa] < rank[pb]

parent[pa]=pb;



Case 2:
-------
rank[pb] < rank[pa]

parent[pb]=pa;



Case 3:
-------
Ranks equal

parent[pb]=pa;

rank[pa]++;


Only when ranks are equal do we increase rank.


===============================================================================
Complete Union Function
===============================================================================

void Union(int a,int b)
{
    int pa=find(a);
    int pb=find(b);

    if(pa==pb)
        return;

    if(rank[pa] < rank[pb])
        parent[pa]=pb;

    else if(rank[pa] > rank[pb])
        parent[pb]=pa;

    else
    {
        parent[pb]=pa;
        rank[pa]++;
    }
}


===============================================================================
Time Complexity
===============================================================================

Without Optimizations:

Find  -> O(N)
Union -> O(N)


With:
-----
✔ Path Compression
✔ Union By Rank


Complexity:

Find  ≈ O(α(N))
Union ≈ O(α(N))


α(N) = Inverse Ackermann Function

Practically:

≈ O(1)


===============================================================================
Key Points to Remember
===============================================================================

• DSU maintains disjoint sets.
• Every set has a representative/root.
• Find returns the representative.
• Union merges two sets.
• Rank stores tree height.
• Path Compression makes Find faster.
• Union by Rank keeps trees balanced.
• DSU is heavily used in Kruskal's MST and cycle detection.

===============================================================================
*/

class DisjointSetUnion{
    int n;
    vector<int> parent, rank;

    public:
    
    DisjointSetUnion(int n){
        this->n = n;
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA==parB) return;

        if(rank[parA]==rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        } else if(rank[parA]>rank[parB]){
            parent[parB] = parA;
        } else{
            parent[parA] = parB;
        }
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);   // Path Compression (read below for explanation)
    }

    void getInfo(){
        cout << "Parent Array: ";
        for(int i=0; i<n; i++){
            cout << parent[i] << " ";
        }
        cout << endl;

        cout << "Rank Array: ";
        for(int i=0; i<n; i++){
            cout << rank[i] << " ";
        }
        cout << endl;
    }

};

/*
===============================================================================
                    PATH COMPRESSION (DSU OPTIMIZATION)
===============================================================================

Idea:
-----
Path Compression is an optimization applied to the Find() operation in DSU.

Goal:
-----
Reduce the depth of the tree so that future Find() operations become faster.


Problem Without Path Compression:
---------------------------------

Consider a skewed tree:

        0
        |
        1
        |
        3
        |
        9


find(9) performs:

9 -> 3 -> 1 -> 0

Multiple recursive calls are needed every time.


Path Compression:
-----------------

While finding the ultimate parent, directly attach every visited node
to the topmost leader.

Before:

        0
        |
        1
        |
        3
        |
        9


After find(9):

        0
      / | \
     1  3  9


Now,

find(9)  -> O(1)
find(3)  -> O(1)
find(1)  -> O(1)


Optimized Find Function:
------------------------

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);  
}


Benefits:
---------
• Converts deep/skewed trees into shallow trees.
• Significantly speeds up future Find() operations.
• Does not change the final answer, only improves efficiency.
• Combined with Union by Rank, DSU operations become almost constant time.


Complexity:
-----------
Theoretical  : O(α(N))
Practical    : ~ O(1)

where α(N) is the Inverse Ackermann Function,
which grows extremely slowly.

===============================================================================
*/

int main(){

    DisjointSetUnion dsu(6);

    dsu.unionByRank(1,2);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}