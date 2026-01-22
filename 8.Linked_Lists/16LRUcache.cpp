#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;


// Leetcode: 146. LRU Cache
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.



// Remember every operation must run in O(1) time complexity.

// We can achieve this by using a combination of a doubly linked list and a hash map (unordered_map in C++). The doubly linked list will maintain the order of usage, with the most recently used items at the front and the least recently used items at the back. The hash map will provide O(1) access to the nodes in the linked list based on their keys.
// We will make dummy head and tail nodes to avoid edge cases in adding and removing nodes.
// So, our linked list will lie between head and tail nodes.

// Everytime we add a new node or access an existing node, we will move that node to the front of the linked list (right after the head).
// When the cache exceeds its capacity, we will remove the node just before the tail (the least recently used node).

class LRUCache {
public:

    // Doubly linked list node structure
    class Node{
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);  // dummy head
    Node* tail = new Node(-1, -1);  // dummy tail
    int limit;                      // cache capacity
    unordered_map<int, Node*> m;    // key-node mapping for O(1) access

    // Initialize LRU cache with given capacity
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head (most recently used position)
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    // Remove a node from the linked list
    void deleteNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;                                        
        oldNext->prev = oldPrev;
    }
    
    // Retrieve value by key, move node to front (recently used)
    int get(int key) {
        if(m.find(key) == m.end()) return -1; // key not found
        Node* ansNode = m[key];
        int ans = ansNode->val;
        m.erase(key);
        deleteNode(ansNode);
        addNode(ansNode); // move to front
        m[key] = ansNode;
        return ans;
    }
    
    // Insert or update a key-value pair
    void put(int key, int value) {
        // If key already exists, delete old node
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        // If capacity full, remove least recently used (before tail)
        if(m.size() == limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Add new node to front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};
