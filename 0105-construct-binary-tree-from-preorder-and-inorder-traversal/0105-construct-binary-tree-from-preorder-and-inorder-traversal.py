# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder:
            return None
        rootVal = preorder[0]
        idx=inorder.index(rootVal)
        lenLeftTree=idx-0
        lenRightTree=len(inorder)-idx
        
        root = TreeNode(rootVal)
        root.left = self.buildTree(preorder[1:1+lenLeftTree] , inorder[:idx])
        root.right = self.buildTree(preorder[1+lenLeftTree:] , inorder[idx+1:])
        
        return root