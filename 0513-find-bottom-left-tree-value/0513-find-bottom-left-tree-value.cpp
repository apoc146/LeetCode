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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        map<int,vector<TreeNode*>,greater<int>> mp;
        int lvl=0;
        while(!que.empty()){
            
            int cnt=que.size();
            
            while(cnt>0){
                auto node=que.front();
                auto left=node->left;
                auto right=node->right;
                
                mp[lvl].push_back(node);
                if(left){
                    que.push(left);
                }
                if(right){
                    que.push(right);
                }
                que.pop();
                cnt--;
            }
            lvl++;
        }
        
        
        return mp.begin()->second[0]->val;
        return -1;
        
    }
};