class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        count = 0
        
        for i in range(len(s)):
            if s[i] == "(":
                count += 1
            elif s[i] == ")":
                if count:
                    count -= 1
                else:
                    s[i] = ""
        
        if count:
            for i in range(len(s) - 1, -1, -1):
                if s[i] == "(":
                    count -= 1
                    s[i] = ""
                if not count:
                    break
        
        return ''.join(s)
