class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.res = None
        self.dfs(root)
        return self.res

    def dfs(self, root, string=''):
        if not root:
            return
    
        if not root.left and not root.right:
            string += chr(ord('a') + root.val)
            if self.res is None:
                self.res = string[::-1]
            else:
                self.res = min(self.res, string[::-1])
            return
    
        string += chr(ord('a') + root.val)

        self.dfs(root.left, string)
        self.dfs(root.right, string)
