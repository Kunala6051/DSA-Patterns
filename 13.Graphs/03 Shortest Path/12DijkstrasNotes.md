
# 📘 DIJKSTRA’S ALGORITHM 

---

## 🔹 1. Shortest Path

* Minimum cost/distance from a **source node → all nodes**
* Used in **weighted graphs**
* Example: Google Maps → distance / time / cost

---

## 🔹 2. Weighted Graph

* Each edge has a **weight**
* Weight can represent:

  * Distance 🚗
  * Cost 💰
  * Time ⏱️

📌 Important:

* We **sum weights**, not number of edges

---

## 🔹 3. Goal

* Find shortest distance from **one source → all vertices**

---

## 🔹 4. Greedy Idea

* Always pick **minimum distance node first**
* Local optimal → global optimal

💡 Intuition:

> Always move via the cheapest path available

---

## 🔹 5. Important Condition ⚠️

* Works only for **non-negative weights**
* For negative weights → use Bellman-Ford

---

## 🔥 6. Edge Relaxation (CORE)

### Condition:

dist[v] > dist[u] + weight(u → v)

### Update:

dist[v] = dist[u] + weight(u → v)

### Meaning:

* Check if going via **u improves v**
* If yes → update

💡 Question:

> “Is it cheaper to reach v through u?”

---

## 📊 7. Graph Representation

* Adjacency List:
  vector<vector<Edge>> graph;

* Edge stores:

  * destination (v)
  * weight (wt)

---

## ⚙️ 8. Data Structures

### 1. Distance Array

* dist[i] = shortest distance from source
* Initialize:

  * source = 0
  * others = ∞

---

### 2. Priority Queue (Min Heap)

* Stores: (distance, node)
* Always gives **minimum distance node**

---

## 🔄 9. Algorithm Steps

### Step 1: Initialization

* dist[] = ∞
* dist[src] = 0
* push (0, src) into PQ

---

### Step 2: While PQ not empty

1. Extract node with minimum distance
2. Traverse its neighbors
3. Apply relaxation

---

### Relaxation Step

If shorter path found:

* update distance
* push into PQ

---

### Step 3: Repeat until PQ empty

---

### Step 4: Result

* dist[] contains shortest paths

---

## 📌 10. Example Result

From source 0:

* 0 → 0 = 0
* 0 → 1 = 2
* 0 → 2 = 3
* 0 → 3 = 8
* 0 → 4 = 6
* 0 → 5 = 9

---

## ⚡ 11. Observations

* Node may appear multiple times in PQ
* Only smallest distance matters
* Dijkstra = BFS + Priority Queue
* Always expands smallest distance first

---

## 🧠 12. Pseudocode (Clean)

* Initialize dist[] = ∞
* dist[src] = 0
* push (0, src)

While PQ not empty:

* pop node u
* for each neighbor v:

  * if dist[v] > dist[u] + w:

    * update dist[v]
    * push (dist[v], v)

---

## 🚀 13. Time Complexity

### Core:

* PQ operation = O(log V)

---

### Total:

O((V + E) log V)

---

### Expanded:

O(V log V + E log V)

---

## 🔹 14. Edge Limits

* Directed: E = V(V−1)
* Undirected: E = V(V−1)/2

👉 Therefore:
E ≤ V²

---

## 🔹 15. Worst Case

O(V² log V)

---

## 🔹 16. Standard Form

Most used:

* O(E log V)

Also valid:

* O(E log E)

---

## 🔍 17. Why O(E log E) = O(E log V)

Since:

* E ≤ V²

So:

* log E = log(V²) = 2 log V

👉 Ignore constant → same complexity

---

## 🔹 18. Graph Types Impact

### Sparse Graph:

* E ≈ V
* Complexity → O(V log V)

### Dense Graph:

* E ≈ V²
* Complexity → O(V² log V)

---

## 🔹 19. Key Takeaways

* Greedy algorithm
* Uses Min Heap
* Core = Edge Relaxation
* Works only for positive weights
* Time complexity → O(E log V)

---

## 🎯 20. One-Line Summary

> Dijkstra finds shortest paths by always expanding the closest node and relaxing edges.

