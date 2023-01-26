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
    void foo(TreeNode* a, TreeNode*b){
            
    }   
    
public:
    TreeNode* invertTree(TreeNode* root) {
        // Left or Null Node
        if(root==NULL or (root->left==NULL && root->right==NULL)){
            return root;
        }   
        
        //swap left and right sub-trees
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        //now invert the subtrees
        invertTree(root->left);
        invertTree(root->right);
    
        //return root
        return root;
        
    }
};