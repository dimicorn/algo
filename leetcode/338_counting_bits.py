class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [bin(i)[2:].count('1') for i in range(n+1)]
        return res
