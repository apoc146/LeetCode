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

    int ans;

    void util(TreeNode* root, double target)
    {
        if(root == NULL)
            return;

        if(target > root->val)
            util(root->right, target);

        if(target < root->val)
            util(root->left, target);
        
        
        if(abs(root->val - target) < abs(ans - target))
            ans = root->val;
        else if(abs(root->val - target) == abs(ans - target))
            ans = min(ans, root->val);

    }

    int closestValue(TreeNode* root, double target) {
        ans = root->val;
        util(root, target);
        return ans;
    }
};