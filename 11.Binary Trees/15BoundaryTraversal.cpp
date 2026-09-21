class Solution{
    void leaf(Node* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(root->data);
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
public:
    vector <int> boundaryTraversal(Node* root){
    	//your code goes here
        vector <int> ans;
        if(!root) return ans;
        
        // Left Boundary
        Node* temp = root;
        if(!root->left){ // If root has no left children then root should be added separately
        // As while condition would break
            ans.push_back(root->data);
        } else{
            while(temp->left!=NULL || temp->right!=NULL){
                // Skipping leaf node + 
                // As if left node is null but right is not
                // Then right node should be included in the boundary as it becomes the part of boundary
                ans.push_back(temp->data);
                if(temp->left) temp = temp->left;
                else temp = temp=temp->right;
            }
        }
        
        if(!root->left && !root->right) return ans; // If there is only 1 node
        // Root node should not be added again as a leaf node
        
        // Leaf Nodes
        leaf(root, ans);
        
        // Right Boundary
        temp = root->right; // As we dont want root to be included again
        if(!temp) return ans;
        vector<int> t; // storing in reverse order starting from root
        while(temp->right!=NULL || temp->left!=NULL){ 
            // Skipping leaf node + 
            // As if right node is null bur left is not
            // Then left node should be included in the boundary as it becomes the part of boundary
            t.push_back(temp->data);
            if(temp->right) temp=temp->right;
            else temp = temp->left;
        }
        for(int i=t.size()-1; i>=0; i--){ // pushing right boundary from bottom to top
            ans.push_back(t[i]);
        }

        return ans;

    }
};