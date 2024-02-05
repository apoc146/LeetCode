/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* foo(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==0){
            return NULL;
        }
        
        if(root->left==0 and root->right==0){
            return root;
        }
        
        
        if(root->val > p->val and root->val<q->val){
            return root;
        }
            
        if(root->val > p->val and root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->val < p->val and root->val < q->val){
            return lowestCommonAncestor(root->right, p , q);
        }    
        return NULL;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == p->val or root->val==q->val){
            return root;
        }
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        
        if(l and r){
            return root;
        }
        return l?l:r;
         
    }
};