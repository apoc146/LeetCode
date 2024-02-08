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

    void dfs(TreeNode* root, int lvl, vector<int>& ans){
        if(root==NULL){
            return ;
        }    
        if(lvl==ans.size()){
            ans.push_back(root->val);
        }
        dfs(root->right,lvl+1,ans);
        dfs(root->left,lvl+1,ans);
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};