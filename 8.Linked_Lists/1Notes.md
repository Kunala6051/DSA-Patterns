

# 📘 Linked List

## 🔹 Introduction

* New Data Structure: **Linked List**
* Concepts used:

  * **OOP (Object-Oriented Programming)**
  * **Pointers**
* Prerequisite:

  * Should understand **Pointers** and **OOPs basics** (classes, objects, constructors).

---

## 🔹 Comparison with Arrays & Vectors

* **Array / Vector**:

  * Data stored in **linear contiguous memory**.
  * Example: If element at address `100`, next will be `104`, `108`, etc.
* **Linked List**:

  * **Linear data structure**, but memory allocation is **non-contiguous**.
  * Elements (called **nodes**) can be stored anywhere in memory.
  * Connected using **pointers** (addresses).

---

## 🔹 Properties of Linked List

1. **Dynamic** (like vectors):

   * Can add or remove nodes at runtime.
   * No fixed size (unlike arrays).

2. **Non-contiguous memory allocation**:

   * Each node can be stored at random addresses in memory.
   * Pointer links them together in a **chain-like structure**.

3. **Implemented in STL (C++ Standard Template Library)**:

   * Available as **`list`** class in STL.
   * But in DSA/interviews → must know how to **implement from scratch**.

---

## 🔹 Node Structure

* A **node** consists of two parts:

  1. **Data** – stores the actual value (e.g., int, char, etc.).
  2. **Pointer (next)** – stores the **address of the next node**.

📌 Example:

* Suppose:

  * Node1 → data = 1, address = 100
  * Node2 → data = 2, address = 200
  * Then: Node1’s `next` = 200 (points to Node2).

* Last node’s `next` → stores **NULL**, since no further node exists.

---

## 🔹 Visualization of Linked List

```
Head → [Data | Next] → [Data | Next] → [Data | Next] → NULL
```

* Each `[Data | Next]` is a node.

* **Head pointer**:

  * Special pointer, stores **address of the first node**.
  * Starting point to traverse the linked list.

* **Tail pointer** (optional):

  * Points to the **last node**.
  * Useful in operations like insertion at the end.

---

## 🔹 Key Differences: Array vs Linked List

| Feature            | Array / Vector              | Linked List                   |
| ------------------ | --------------------------- | ----------------------------- |
| Memory Allocation  | Contiguous                  | Non-contiguous (scattered)    |
| Size               | Fixed (unless using vector) | Dynamic (can grow/shrink)     |
| Access             | O(1) using index            | O(n), must traverse from head |
| Insertion/Deletion | Costly (shifting elements)  | Easy (just change pointers)   |

---

## 🔹 Access in Linked List

* No direct index-based access like arrays.
* To get element at position `i`, must traverse **node by node** → O(n).
* Only way to start traversal = **Head pointer**.

---

## 🔹 Implementation Plan in C++

We need **two classes**:

### 1. **Node Class**

* Stores **data** and **next pointer**.
* Contains a constructor to initialize node.

```cpp
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL; // initially no next node
    }
};
```

---

### 2. **List (LinkedList) Class**

* Manages the entire linked list.

* Stores:

  * **Head pointer** → first node
  * **Tail pointer** → last node

* Constructor initializes empty list (head = NULL, tail = NULL).

```cpp
class List {
    Node* head;
    Node* tail;

public:
    // Constructor for empty list
    List() {
        head = NULL;
        tail = NULL;
    }
};
```

---

## 🔹 Summary Till Now

1. **Linked List** = linear DS using **nodes + pointers**.
2. **Node** = (data + pointer to next node).
3. **Head pointer** → start of list, **Tail pointer** (optional).
4. Difference from arrays: **non-contiguous memory, dynamic size, O(n) access**.
5. Implementation:

   * **Node class** → creates nodes.
   * **List class** → manages nodes using head & tail.

---

👉 Next steps in lecture (after this point):

* Implement functions to:

  * Insert nodes (beginning, end, middle).
  * Delete nodes.
  * Traverse/print linked list.
  * Handle edge cases (empty list, single node).


Got it 👍 Let’s break it down carefully:

```cpp
Node* head;
Node* tail;
```

---

## 🔹 Step 1: What is `Node`?

Earlier, we defined a **Node class**:

```cpp
class Node {
public:
    int data;      // value stored in the node
    Node* next;    // pointer to next node
};
```

* Here, `Node` is a **class** (or user-defined data type).
* `Node*` means **pointer to a Node object**.

So whenever you see `Node*`, think of **“address of a Node in memory”**.

---

## 🔹 Step 2: What is `head`?

* `head` is a **pointer to the first node** of the linked list.
* It **always points to the starting node**.
* Without `head`, we lose the linked list because we don’t know where it starts.

Example:

```
head → [10 | next] → [20 | next] → [30 | next] → NULL
```

* Here, `head` stores the **address of the node containing 10**.

---

## 🔹 Step 3: What is `tail`?

* `tail` is a **pointer to the last node** of the linked list.
* It makes **insertion at the end easy**, because we don’t need to traverse the whole list.

Example:

```
head → [10 | next] → [20 | next] → [30 | NULL] ← tail
```

* Here, `tail` stores the **address of the node containing 30**.
* Notice `tail->next = NULL` because there’s no further node.

---

## 🔹 Step 4: Why do we need both?

* **`head`** → so we always know where the list starts.
* **`tail`** → so we can quickly add at the end (O(1) instead of O(n)).

📌 Without `tail`, if you want to add at the end, you must start from `head` and traverse until the last node → O(n).
📌 With `tail`, you directly add → O(1).

---

✅ In short:

* `Node* head;` → pointer to **first node**.
* `Node* tail;` → pointer to **last node**.




Perfect 👌 You’ve shared the next big chunk of the lecture (from **initializing head/tail to push\_front implementation and printing**). Let me make **structured, detailed notes** from it so you can revise easily:

---

# 📘 Linked List – Implementation Notes (Push Front + Print)

## 🔹 Initialization of Head & Tail

* When a new **Linked List object** is created:

  * Initially, the list is **empty** (no nodes).
  * So, both pointers are set to `NULL`:

    ```cpp
    Node* head = NULL;
    Node* tail = NULL;
    ```
* Meaning:

  * `head = NULL` → No starting node.
  * `tail = NULL` → No ending node.

---

## 🔹 Major Functions in a Linked List

Every linked list implementation usually provides these **four core operations**:

1. **push\_front(value)**

   * Insert new node at the **beginning** of the list.
   * Updates `head`.

2. **push\_back(value)**

   * Insert new node at the **end** of the list.
   * Updates `tail`.

3. **pop\_front()**

   * Delete node from the **beginning** of the list.

4. **pop\_back()**

   * Delete node from the **end** of the list.

🔸 Extra useful operations:

* **insert(position, value)** → insert in middle.
* **search(value)** → check if value exists.

---

## 🔹 Focus: `push_front(value)`

We handle **two cases** while inserting at front:

### Case 1: Empty Linked List

* If `head == NULL`:

  1. Create a **new node** for the given value.
  2. That node becomes both **head** and **tail**.
  3. Its `next = NULL` (by default).

📌 Example:
Push `1` in empty list:

```
head → [1 | NULL] ← tail
```

---

### Case 2: Non-Empty Linked List

* If list already has nodes (`head != NULL`):

  1. Create a **new node** with given value.
  2. Set `newNode->next = head` (connect new node to current head).
  3. Update `head = newNode` (new node becomes the first node).

📌 Example:
If list = `[1 → NULL]` and we push\_front(2):

```
head → [2 | *] → [1 | NULL] ← tail
```

---

## 🔹 Code for `push_front`

```cpp
class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int value) {
        // Step 1: Create new node dynamically
        Node* newNode = new Node(value);

        // Case 1: Empty list
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // Case 2: Non-empty list
        newNode->next = head;
        head = newNode;
    }
};
```

---

## 🔹 Why `new` keyword (Dynamic Allocation)?

* `new` ensures node **persists in memory** even after function ends.
* If we used static object (`Node newNode(value);`), it would be destroyed when function exits.
* With `new`, node remains allocated until we explicitly delete it.

---

## 🔹 Printing the Linked List

* We can only traverse from **head** (sometimes tail is also given, but usually head is enough).
* Steps:

  1. Create a **temporary pointer** (`temp = head`).
  2. Loop while `temp != NULL`:

     * Print `temp->data`.
     * Move `temp = temp->next`.

### Code:

```cpp
void print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
```

---

## 🔹 Example Execution

```cpp
List ll;
ll.push_front(1);
ll.push_front(2);
ll.push_front(3);

ll.print();
```

Output:

```
3 → 2 → 1 → NULL
```

---

✅ So far, we can:

* Initialize empty list (`head = tail = NULL`).
* Insert nodes at **front** (`push_front`).
* Print full list (`print`).

