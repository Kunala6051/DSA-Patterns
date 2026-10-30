// Leetcode Problem: 785. Is Graph Bipartite?

/*
WHAT IS A BIPARTITE GRAPH?
--------------------------
A graph is bipartite if we can divide its vertices into two groups
such that no two adjacent vertices belong to the same group.

We can visualize this as coloring every vertex using two colors:
Color 0 and Color 1.

RULES:
1. Every edge must connect vertices of different colors.
2. If two adjacent vertices have the same color, the graph is NOT bipartite.
3. A graph can be disconnected, so we must check every component.

APPROACH: DFS + 2-COLORING
--------------------------
1. Initially, color every vertex -1 (uncolored).
2. Start DFS from every uncolored vertex and assign it color 0.
3. For every neighbor:
   - If uncolored, assign it the opposite color and explore it.
   - If already colored with the same color as the current vertex,
     a conflict exists, so the graph is NOT bipartite.
4. If every component is colored without a conflict, return true.

WHY DOES IT WORK?
-----------------
Every neighbor must have the opposite color.
DFS propagates this requirement throughout the graph.
If we encounter an edge whose endpoints have the same color,
we cannot divide the graph into two valid groups.
*/

class Solution {
    bool dfs(int i, int c, vector<vector<int>>& graph,
             vector<int>& color) {

        color[i] = c;  // Assign the current vertex its color (0 or 1)

        // Visit every neighbor of the current vertex
        for (int j : graph[i]) {

            // If the neighbor has not been colored yet
            if (color[j] == -1) {

                // Give it the opposite color and continue DFS
                // !c changes 0 to 1 and 1 to 0
                if (!dfs(j, !c, graph, color))
                    return false;  // A conflict was found deeper in DFS

            }
            // If the neighbor has the same color, the graph is not bipartite
            else if (color[j] == c) {
                return false;
            }
        }

        return true;  // No coloring conflict in this DFS component
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        // -1 means uncolored; 0 and 1 represent the two groups
        vector<int> color(v, -1);

        // Check every vertex because the graph may be disconnected
        for (int i = 0; i < v; i++) {

            // Start DFS only if this vertex has not been visited
            if (color[i] == -1) {

                // Start this component with color 0
                if (!dfs(i, 0, graph, color))
                    return false;
            }
        }

        // Every component was colored without a conflict
        return true;
    }
};