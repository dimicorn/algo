class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        return self.dfs(root, val, depth)
    def dfs(self, root, val, depth, cur_depth=1):
        if depth == 1:
            childLeft = root
            newRoot = TreeNode(val, childLeft, None)
            return newRoot
        
        if not root:
            return
        
        if depth - 1 == cur_depth:
            childLeft, childRight = root.left, root.right
            newChildLeft = TreeNode(val, childLeft, None)
            newChildRight = TreeNode(val, None, childRight)
            root.left, root.right = newChildLeft, newChildRight
            return root
        
        self.dfs(root.left, val, depth, cur_depth+1)
        self.dfs(root.right, val, depth, cur_depth+1)
        return root
