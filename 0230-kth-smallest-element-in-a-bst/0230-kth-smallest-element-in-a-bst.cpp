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
    int k=-1;
    int ans=-1;
    void foo(TreeNode* root, vector<int>& vec){
        if(root==NULL){
            return ;
        }

        foo(root->left, vec);
        vec.push_back(root->val);
        foo(root->right, vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        vector<int> vec;
        foo(root, vec);
        return vec[k-1];
        
    }
};