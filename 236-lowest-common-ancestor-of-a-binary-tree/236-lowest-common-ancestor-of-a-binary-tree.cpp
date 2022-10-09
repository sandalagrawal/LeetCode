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
    // this is the first method to find the lowest common ancestor, using path.
    
    // using this function we find the paths of the given node from the root node.
    bool findPath(TreeNode* root, vector<TreeNode*>&path, TreeNode* node)
    {
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root==node)
            return true;
        if(findPath(root->left,path,node) || findPath(root->right,path,node))
            return true;
        path.pop_back();
        return false;
        
    }
    
    // using this node we will find the lowest common ancestor, by comparing the two paths
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;  // we declared the two paths for the two nodes
       
        
        //if either path1 or path2 does not exist, we will return null.
        if(! findPath(root, path1, p) || ! findPath(root, path2, q))   
            return NULL;
        TreeNode* ans = NULL;
        
        
        // here we'll find the ans, by comparing the two paths
        for(int i=0;i<path1.size() && i< path2.size();i++)
        {
            if(path1[i]==path2[i])
                ans = path1[i];
        }
        
        return ans;
    }
};