// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    // Constructor to initialize a node with a given value
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Edge case: if the original list is empty, return NULL
        if (head == NULL) return NULL;

        // Hash map to store the mapping between original nodes and their copies
        unordered_map<Node*, Node*> corr;

        // Step 1: Create the new head node (copy of the original head)
        Node* newHead = new Node(head->val);

        // Temporary pointers to traverse the original and copied list

        Node* oldTemp = head->next;
        // oldTemp points to the second node in the original list as the first is already copied
        Node* newTemp = newHead;

        // Store the mapping of original head to copied head
        corr[head] = newHead;

        // Step 2: Copy all nodes (without setting random pointers yet)
        while (oldTemp != NULL) {
            // Create a new node (copy of the current original node)
            Node* copyNode = new Node(oldTemp->val);

            // Store the mapping between original node and copied node
            corr[oldTemp] = copyNode;

            // Link the copied node in the new list
            newTemp->next = copyNode;

            // Move both temp pointers forward
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }
        
        // Step 3: Set up random pointers in the copied list
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            // Set the random pointer of the new node
            // corr[oldTemp->random] gives the corresponding copied node for oldTemp->random
            newTemp->random = corr[oldTemp->random];

            // Move both temp pointers forward
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        // Step 4: Return the head of the deep-copied linked list
        return newHead;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the original list. We traverse the list a constant number of times.
// Space Complexity: O(N) for the hash map that stores the mapping between original nodes and their copies.