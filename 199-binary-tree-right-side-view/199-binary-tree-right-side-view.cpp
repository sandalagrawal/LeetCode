/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       // we'll make use of level order traversal with certain changes
        
        vector<int> ans;
        queue<TreeNode*>q;
         q.push(root);
        if(root==NULL){
            return ans;
        }
        
       
        while(1){
            int n = q.size();
            if(n==0)
            {
                return ans;
            }
            
            int data=0;
            while(n>0)
            {
                TreeNode* temp = q.front();
                q.pop();
                data = temp->val;
                
                if(temp->left!=NULL){
                     q.push(temp->left);

                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
                n--;
                
            }
            ans.push_back(data);
        }

      return ans;
    }
    
};









  // pehli baar me likha hua code
        /*vector<int> ans;
        if(root==NULL){
            return ans;

        }
        ans.push_back(root->val);
        TreeNode* temp = root;
        while(temp!=NULL)
        {
           // ans.push_back(temp->val);
            if(temp->right){
                ans.push_back(temp->right->val);
            }
            temp = temp->right;

        }
        return ans;*/