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
// class Solution {
// public:
//     void foo(TreeNode* root, int diff, unordered_map<int,vector<int>>& mp){
//         if(root==NULL){
//             return ;
//         }
        
//         mp[diff].push_back(root->val);
//         foo(root->left,diff-1,mp);
//         foo(root->right,diff+1,mp);
//     }
    
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         unordered_map<int, vector<int>> mp;
//         foo(root,0,mp);
//         map<int,vector<int>> omp(mp.begin(),mp.end());
        
//         for(auto& it : omp) {
//             // Push the values corresponding to each key into the result vector
//             ans.push_back(it.second);
//         } 
//         return ans;
//     }
// };


class Solution {
public:
    map<int, multimap<int, int>> mp; // Use a single map to store nodes based on their column and row

    void dfs(TreeNode* root, int col, int row) {
        if (root == NULL) {
            return;
        }
        
        mp[col].insert({row, root->val}); // Store nodes along with their row number
        
        dfs(root->left, col - 1, row + 1);
        dfs(root->right, col + 1, row + 1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        
        // Convert map into answer format (vector of vectors)
        vector<vector<int>> ans;
        for (auto& pair : mp) {
            vector<int> colNodes;
            for (auto& p : pair.second) {
                colNodes.push_back(p.second); // Extract node values
            }
            ans.push_back(colNodes); // Push nodes in the correct order of columns
        }
        
        return ans;
    }
};


