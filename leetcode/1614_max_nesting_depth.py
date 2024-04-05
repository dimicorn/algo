class Solution:
    def maxDepth(self, s: str) -> int:
        count = 0
        res = 0
        for ch in s:
            if ch == '(':
                count += 1
            elif ch == ')':
                count -= 1
            res = max(res, count)
        
        return res
