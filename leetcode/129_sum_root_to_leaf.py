class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        string = ''
        self.sum = 0
        self.dfs(root, string)
        return self.sum
    
    def dfs(self, root, string):
        if not root:
            return
            
        if not root.left and not root.right:
            string += str(root.val)
            print(string)
            self.sum += int(string)
            return
        
        string += str(root.val)

        self.dfs(root.left, string)
        self.dfs(root.right, string)
