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
    bool treeSame(TreeNode* r1, TreeNode* r2){
        if(!r1 and !r2){
            return true;
        }
        
        if( (!r1 and r2) or (r1 and !r2)){
            return false;
        }
        
        return ((r1 and r2) and (r1->val == r2->val) and treeSame(r1->left,r2->left) and  treeSame(r1->right,r2->right));
        
    }
    
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            return false;
        }
        
        bool val1=treeSame(root,subRoot);
        bool val2=dfs(root->left, subRoot);
        bool val3=dfs(root->right, subRoot);
        return val1 | val2 | val3;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            return dfs(root, subRoot);
    }
};