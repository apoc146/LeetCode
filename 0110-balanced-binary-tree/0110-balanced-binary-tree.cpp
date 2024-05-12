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
typedef TreeNode* Node;
class Solution {
public:
    int height(Node root){
        if(!root){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }    
        if(!root->left and !root->right){
            return true;
        }
        int lht=height(root->left);
        int rht=height(root->right);
        return abs(lht-rht)<=1 and isBalanced(root->left) and isBalanced(root->right);
    }
};