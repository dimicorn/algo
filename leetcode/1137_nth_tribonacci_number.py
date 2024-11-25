class Solution:
    def tribonacci(self, n: int) -> int:
        t_0, t_1, t_2 = 0, 1, 1
        
        if n == 0:
            return t_0
        if n == 1 or n == 2:
            return t_1
        
        res = 0
        for i in range(3, n+1):
            res = t_0 + t_1 + t_2
            t_0, t_1, t_2 = t_1, t_2, res
        return res
