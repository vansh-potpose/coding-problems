# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if(q is None and p is None):
            return True
        elif(q is None or p is None):
            return False
        elif(p.val==q.val):
            if(self.isSameTree(p.left,q.left)):
                return self.isSameTree(p.right,q.right)
            else:
                 return False
        else:
            return False
        