# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.flag = True
        self.dfs(p, q)
        return self.flag

    def dfs(self, p, q):
        if p is None and q is None:
            return
        elif p is None or q is None:
            self.flag = False
            return
        
        if p.val != q.val:
            self.flag = False
        
        self.dfs(p.left, q.left)
        self.dfs(p.right, q.right)
