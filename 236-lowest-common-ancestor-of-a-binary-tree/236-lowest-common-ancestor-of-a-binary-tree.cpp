/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // we'll solve this by taking in consideration 4 cases
        
        //case 1 : if our root is null
        if(root==NULL)
            return NULL;
        
        //if our root is equal to one of the nodes
        if(root==p || root==q)
            return root;
        
        // we'll dinf for the left subtree and right subtree
        TreeNode* LCA1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* LCA2 = lowestCommonAncestor(root->right,p,q);
        
        
        // agr left subtree and rightsubtree dono not null hai toh root will be our ans
        if(LCA1 != NULL && LCA2 != NULL)
            return root;
        
        // wrna agr left subtree not null hai toh return that, else return right subtree
        if(LCA1 != NULL)
            return LCA1;
        else
            return LCA2;
    }
};