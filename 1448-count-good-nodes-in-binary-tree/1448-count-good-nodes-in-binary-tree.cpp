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
    //A function to return # of good nodes
    int foo(TreeNode* root, int maxVal){
        if(root==NULL){
            return 0;
        }
        
        int count=0;
        if(root->val>=maxVal){
            count=1;
        }
        
        maxVal=max(maxVal,root->val);
        count+=foo(root->left,maxVal);
        count+=foo(root->right,maxVal);
        return count;
    }
    
    int goodNodes(TreeNode* root) {
      return foo(root,root->val);  
    }
};


