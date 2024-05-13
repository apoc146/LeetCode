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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();
            while(size-->0){
                TreeNode* node=q.front();
                q.pop();
                temp.emplace_back(node->val);
                TreeNode* left=node->left;
                TreeNode* right=node->right;
                if(left){
                    q.push(left);
                }
                if(right){
                    q.push(right);
                }
            }
            ans.push_back(temp); 
        }
        return ans;
    }
};