#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- This problem can be thought of as a variation of Dijkstra's Algorithm.
- Instead of finding the shortest path with no restrictions, we need the
  cheapest path while using at most k stops. So, we make a few modifications
  to the usual shortest path approach.
- First, represent the flights as a directed weighted graph using an adjacency list,
  where each edge stores the destination city and the flight cost.
- Instead of using a priority queue like Dijkstra, we use a normal queue because
  the number of stops is the primary constraint, and we only explore paths that
  satisfy the stop limit.
- Each queue element stores:
      {current city, {total cost so far, stops used}}
- Start from the source city with cost = 0 and stops = -1.
  We initialize stops as -1 so that after taking the first flight,
  the number of stops becomes 0.
- For every city removed from the queue, explore all of its outgoing flights.
  If moving to a neighboring city:
    - gives a cheaper cost than previously found, and
    - the total stops do not exceed k,
  then update its minimum cost and push the new state into the queue.
- Continue this process until all valid paths have been explored.
- Finally, if the destination is reachable within k stops, return its minimum
  cost; otherwise, return -1.

Time Complexity: O(E)
Space Complexity: O(V + E)
*/



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }

        // Minimum cost to reach each city
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // {city, {cost, stops}}
        queue<pair<int, pair<int,int>>> q;
        q.push({src, {0, -1}});

        while(!q.empty()){
            int u = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();

            // Explore all outgoing flights
            for(pair<int,int> e : adj[u]){
                int v = e.first;
                int wt = e.second; // dist from u to v

                // Relax edge if cheaper and within stop limit
                if(dist[v] > cost + wt && stops + 1 <= k){
                    dist[v] = cost + wt;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        // Destination not reachable
        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};

int main() {
    Solution obj;

    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,3,100},
        {0,2,500}
    };

    int src = 0;
    int dst = 3;
    int k = 2;

    cout << obj.findCheapestPrice(n, flights, src, dst, k) << endl;
    // Output: 300

    return 0;
}