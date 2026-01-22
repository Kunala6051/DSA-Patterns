class Solution {
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(!p || !q) return p==q;

        bool isLeftIdentical = isIdentical(p->left, q->left);
        bool isRightIdentical = isIdentical(p->right, q->right);

        return isLeftIdentical && isRightIdentical && p->val==q->val;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL || subroot==NULL) return root==subroot;
        if(isIdentical(root,subroot)) return true;

        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
    }
};
