# Graph Data Structure — Notes

## 1. Introduction to Graph

* **Graph** is an important **Data Structure** used to represent **networks of nodes**.
* It is commonly asked in **coding interviews**, especially in **product-based companies**.
* Many problems in interviews involve **Graphs and Dynamic Programming**.

### Definition

A **Graph** is a **network of nodes connected by edges**.

* **Nodes** → called **Vertices (Vertex)**
* **Connections between nodes** → called **Edges**

Example visualization:

```
A ---- B
|      |
C ---- D
```

### Key Point

* Unlike **Trees**, graphs **do not have hierarchy**.
* There is **no parent-child relationship**.
* Nodes are simply **connected to each other**.

---

# 2. Graph Terminology

| Term          | Meaning                            |
| ------------- | ---------------------------------- |
| Vertex (Node) | Individual element in graph        |
| Vertices      | Collection of nodes                |
| Edge          | Connection between two nodes       |
| Path          | Sequence of edges connecting nodes |
| Neighbor      | Directly connected node            |

---

# 3. Real Life Applications of Graphs

Graphs appear in many real-world systems.

### 1️⃣ Maps / Navigation Systems

Examples:

* Google Maps
* Uber
* Ola

Cities = **Vertices**
Roads = **Edges**

Example:

```
City A ---- City B
   |           |
City C ---- City D
```

Graph helps find:

* Shortest path
* Optimal routes

---

### 2️⃣ Social Networks

Example: Facebook / Instagram

Users = **Vertices**
Friend connections = **Edges**

Example:

```
A --- B
|     |
E --- C
      |
      D
```

---

### 3️⃣ Machine Learning

Graphs are used in:

* **Neural Networks**
* **Graph Neural Networks (GNN)**

---

# 4. Are Graphs Difficult?

Graph problems sometimes appear difficult because:

* Problems are **long**
* Multiple concepts involved

  * vertices
  * edges
  * algorithms
  * edge cases

However, the **core concept of graphs is simple**.

---

# 5. Types of Graphs (Based on Edge Direction)

## 1️⃣ Directed Graph

Edges have **direction**.

Example:

```
1 → 2 → 3
```

Meaning:

* 1 connects to 2
* 2 connects to 3
* But reverse may not exist

Also called:

* **Unidirectional graph**

---

## 2️⃣ Undirected Graph

Edges have **no direction**.

Example:

```
1 — 2 — 3
```

Meaning:

* 1 ↔ 2
* 2 ↔ 3

Also called:

* **Bidirectional graph**

---

# 6. Types of Graphs (Based on Edge Weight)

## 1️⃣ Weighted Graph

Edges have **values (weights)**.

Example:

```
A --10--> B
B --9--> C
```

Weights can represent:

* Distance
* Cost
* Time
* Profit / loss

Example:

```
City1 --10km--> City2
City2 --9km--> City3
```

Weights can also be **negative**.

Example:

```
A --(-10)--> B
```

Meaning: gain or reward.

---

## 2️⃣ Unweighted Graph

Edges **do not have weights**.

Example:

```
A --- B
|     |
C --- D
```

---

# 7. Combined Graph Types

Based on **direction + weight**:

| Type                    | Description                 |
| ----------------------- | --------------------------- |
| Undirected + Unweighted | Normal graph                |
| Undirected + Weighted   | Road network with distances |
| Directed + Weighted     | Traffic system              |
| Directed + Unweighted   | Simple one-way connections  |

---

# 8. Connected vs Disconnected Graph

## Connected Graph

All nodes are reachable.

Example:

```
1 --- 2
|     |
3 --- 4
```

Every node can reach another node.

---

## Disconnected Graph

Graph has **multiple components**.

Example:

```
1 --- 2 --- 3

4
```

Node **4** is not connected to others.

So graph has **two components**.

---

# 9. Graph Representation in Programming

Graphs can be stored using:

1️⃣ **Adjacency List**
2️⃣ **Adjacency Matrix**

Most common: **Adjacency List**

---

# 10. Adjacency List Representation

Idea:

For **each vertex**, store **all its neighbors**.

```
Store neighbors for all vertices
```

Notation:

* **V** → number of vertices
* **E** → number of edges

---

### Example Graph

```
0 -- 1
     |
     2
     |
     3
```

Vertices:

```
0,1,2,3
```

---

### Adjacency List

```
0 → 1
1 → 0,2,3
2 → 1,3
3 → 1,2
```

Meaning:

* 0 connected to 1
* 1 connected to 0,2,3
* 2 connected to 1,3
* 3 connected to 1,2

---

# 11. How We Store Adjacency List in C++

Each vertex stores **list of neighbors**.

### Structure

```
vector<list<int>> adj
```

or

```
list<int> adj[V]
```

Each index = vertex
Each list = neighbors

---

### Example Storage

| Vertex | Neighbors |
| ------ | --------- |
| 0      | 1         |
| 1      | 0,2,3     |
| 2      | 1,3       |
| 3      | 1,2       |

---

# 12. STL List in C++

C++ `list` is implemented as:

**Doubly Linked List**

Operations:

### Insert

```
push_back()
push_front()
```

### Delete

```
pop_back()
pop_front()
```

### Access

```
front()
back()
size()
```

---

# 13. Why Use Dynamic Array for Graph?

Because:

* Number of vertices **varies**
* Graph size **not known beforehand**

Example:

Graph 1 → 4 vertices
Graph 2 → 100 vertices

So we use **dynamic allocation**.

---

# 14. Dynamic Array for Graph

Instead of

```
int arr[]
```

We use:

```
list<int>* adj
```

Meaning:

* `adj` → dynamic array
* Each index contains **list of neighbors**

---

# Final Concept Summary

Graph = **Vertices + Edges**

Important ideas:

1️⃣ Graph is a **network of nodes**

2️⃣ Types of Graphs:

* Directed
* Undirected
* Weighted
* Unweighted

3️⃣ Graph Structure:

* Connected
* Disconnected

4️⃣ Graph Representation:

* Adjacency List (most common)

5️⃣ C++ Implementation:

```
list<int>* adj;
```

Each vertex stores **list of its neighbors**.

---