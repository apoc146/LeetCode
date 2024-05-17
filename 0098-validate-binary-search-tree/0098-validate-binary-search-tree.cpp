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
    
    bool foo(TreeNode* root, long min, long max){
        
        if(root==NULL){
            return true;
        }
        
        if(root->val <= min or root->val >=max){
            return false;    
        }
        
        return root and (root->val > min and root->val < max) and foo(root->left, min, root->val) and foo(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        return foo(root, -1e10, 1e10);
    }
};