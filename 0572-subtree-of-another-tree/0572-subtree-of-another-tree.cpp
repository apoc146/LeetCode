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
    bool isSame(TreeNode* r1, TreeNode* r2){
        if(!r1 and !r2){
            return true;
        }
        
        if((!r1 and r2) or (r1 and !r2)){
            return false;
        }
        
        if(r1->val!=r2->val){
            return false;
        }
        
        return ((r1->val == r2->val) and (isSame(r1->left, r2->left)) and (isSame(r1->right, r2->right)));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL or subRoot == nullptr){
            return false;
        }
        
        return isSame(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        
    }
};