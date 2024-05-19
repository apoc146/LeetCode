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
    void dfs(TreeNode* root, vector<int>& cur, vector<vector<int>>& ans){
        if(!root){
            return ;
        } 
        
        cur.push_back(root->val);
        
        if (!root->left && !root->right) {
            ans.push_back(cur);
        } else {
            dfs(root->left, cur, ans);
            dfs(root->right, cur, ans);
        }
        
        cur.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> cur;
        vector<vector<int>> ans;
        dfs(root, cur, ans);
        int sum=0;
        for(auto numDigits:ans){
            reverse(numDigits.begin(), numDigits.end());
            int base=0;
            int num=0;
            for(auto digit:numDigits){
                num+=digit*pow(10,base);
                base++;
            }
            sum+=num;
        }
        return sum;
    }
};