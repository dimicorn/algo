class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        res, p2, p1 = 0, 0, 1
        for i in range(1, n):
            res = p1 + p2
            p2, p1 = p1, res
        return res
