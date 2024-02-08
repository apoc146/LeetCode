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
    int lowCheck=-1;
    int highCheck=-1;
public:
    int check(int val){
        if(val>=lowCheck and val<=highCheck){
            return val;
        }    
        return 0;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->lowCheck=low;
        this->highCheck=high;
        
        if(root==NULL){
            return 0;
        }
        
        int leftSum=rangeSumBST(root->left,low,high);
        int rightSum=rangeSumBST(root->right,low,high);
        
        int ansSum=(check(root->val)+leftSum+rightSum);
        return ansSum;
        
        
    }
};