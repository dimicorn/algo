class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.s = 0
        self.dfs(root, 0)
        return self.s

    def dfs(self, root, flag):
        if not root:
            return
        if not root.left and not root.right and flag == 1:
            self.s += root.val
        
        self.dfs(root.left, 1)
        self.dfs(root.right, 0)
