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
    int  mx=INT_MIN;
    int dfs(TreeNode* root, int maxVal){
        if(root==NULL){
            return 0;
        }        
        
        int left=dfs(root->left, maxVal);
        int right=dfs(root->right, maxVal);
        left=max(0,left);
        right=max(0,right);
        
        int wholePathSum=root->val+left+right;
        mx=max(mx,wholePathSum);
        
        return root->val+max(left, right); 
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root,mx);
        return mx;
    }
};