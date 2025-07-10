# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if(root is None):
            return False
        if(root.left is None and root.right is None):
            return not(root.val-targetSum)
        if(root.left is None):
            return self.hasPathSum(root.right,targetSum-root.val)
        if(root.right is None):
            return self.hasPathSum(root.left,targetSum-root.val)
        return (self.hasPathSum(root.left,targetSum-root.val) or self.hasPathSum(root.right,targetSum-root.val))
        