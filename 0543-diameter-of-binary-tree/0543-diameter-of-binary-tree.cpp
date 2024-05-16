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
private: 
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right); 
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL){
           return 0;
       } 
        
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);
        int leftHt=height(root->left);
        int rightHt=height(root->right);
        
        return max(max(leftDia,rightDia),leftHt+rightHt);

    }
};