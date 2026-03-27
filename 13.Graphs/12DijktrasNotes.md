# 📘 DIJKSTRA’S ALGORITHM — COMPLETE NOTES

---

## 🔹 1. What is Shortest Path?

* **Shortest path** = Minimum cost/distance from a source node to all other nodes.
* Used in **weighted graphs**.

👉 Example:

* Like Google Maps
  → weight = distance / time / cost

---

## 🔹 2. Weighted Graph

* A graph where each edge has a **weight (value)**.
* Weight can represent:

  * Distance 🚗
  * Cost 💰
  * Time ⏱️

📌 Important:

* We don’t count number of edges
* We **sum weights**

---

## 🔹 3. Goal of Dijkstra’s Algorithm

* Find **shortest distance from ONE source node → ALL nodes**

---

## 🔹 4. Key Idea (Greedy Algorithm)

👉 Dijkstra is a **Greedy Algorithm**

### 🔹 What is Greedy?

* At every step → choose **best (minimum) option locally**
* Leads to **global optimal solution**

💡 Intuition:

> Always pick the **shortest available path first**

---

## 🔹 5. Important Condition ⚠️

❌ Works ONLY for:

* **Positive weights (≥ 0)**

❌ If negative weights exist → use:

* Bellman-Ford Algorithm

---

# 🔥 6. Core Concept: Edge Relaxation (VERY IMPORTANT)

### 🔹 Formula:

If:

```
dist[v] > dist[u] + weight(u → v)

dist[v] = Distance of v from source
dist[u] = Distance of u from source
weight = weight from u to v
```

Then:

```
dist[v] = dist[u] + weight(u → v)
(Updating the value)
```

---

### 🔹 Meaning:

* Check if going via **u → v** is shorter than current path
* If yes → update distance

---

### 🔹 Intuition:

> “Is it cheaper to reach v through u?”

✔ If YES → update
✔ If NO → ignore

---

# 📊 7. Graph Representation

### Using Adjacency List

```cpp
vector<vector<Edge>> graph;
```

Each edge stores:

```cpp
class Edge {
    int destination; (from source to curr vertex)
    int weight;
};
```

---

# ⚙️ 8. Data Structures Used

## 🔹 1. Distance Array

```cpp
vector<int> dist(V, INT_MAX);
```

* Stores shortest distances
* Initialize:

  * Source → 0
  * Others → ∞

---

## 🔹 2. Priority Queue (Min Heap)

* Stores: `(distance, node)`

👉 Important:

* Distance is stored **first**
* Sorting is based on **distance**

---

### 🔹 Why Priority Queue?

* Always gives **minimum distance node first**
* Needed for greedy approach

---

# 🔄 9. Algorithm Steps (Step-by-Step)

---

## 🟢 Step 1: Initialization

* Create distance array → all ∞
* Set source = 0
* Push `(0, source)` into PQ

---

## 🟢 Step 2: While PQ not empty

### 1. Extract minimum node

```cpp
auto [dist_u, u] = pq.top();
pq.pop();
```

---

### 2. Traverse all neighbors of u

For each edge:

```cpp
u → v with weight w
```

---

### 3. Apply Edge Relaxation

```cpp
if (dist[v] > dist[u] + w) {
    dist[v] = dist[u] + w;
    pq.push({dist[v], v});
}
```

---

## 🟢 Step 3: Repeat until PQ empty

---

## 🟢 Step 4: Final Result

* `dist[]` contains shortest distances

---

# 📌 10. Example Result

Final distances from source (0):

```
0 → 0 = 0
0 → 1 = 2
0 → 2 = 3
0 → 3 = 8
0 → 4 = 6
0 → 5 = 9
```

---

# ⚡ 11. Important Observations

### 🔹 1. Node can appear multiple times in PQ

* Old distances remain
* Only smallest one matters

---

### 🔹 2. BFS + Priority Queue

* Dijkstra = **Modified BFS**
* Uses PQ instead of normal queue

---

### 🔹 3. Greedy Behavior

* Always expand **minimum distance node first**

---

# 🧠 12. Pseudocode (Exam Ready)

```cpp
Initialize dist[V] = INT_MAX
dist[source] = 0

PriorityQueue pq
pq.push({0, source})

while (!pq.empty()) {
    u = pq.top().second
    pq.pop()

    for each neighbor v of u {
        if (dist[v] > dist[u] + weight(u,v)) {
            dist[v] = dist[u] + weight(u,v)
            pq.push({dist[v], v})
        }
    }
}
```

---

# 🚀 13. Complexity

| Operation | Complexity |
| --------- | ---------- |
| Using PQ  | O(E log V) |

---

# 🎯 14. Key Points for Exams

* ✔ Works only for **positive weights**
* ✔ Uses **Greedy approach**
* ✔ Core = **Edge Relaxation**
* ✔ Uses **Min Heap (Priority Queue)**
* ✔ Finds **single source shortest path**

---

# 💡 15. One-Line Summary

> Dijkstra repeatedly picks the nearest node and relaxes its edges to find shortest paths.

