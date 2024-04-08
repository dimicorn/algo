class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * n
        res = 0
        dp[0], dp[1] = cost[0], cost[1]
        for i in range(2, n):
            p1, p2 = cost[i-2], cost[i-1]
            dp[i] += cost[i] + min(dp[i-1], dp[i-2])
        return min(dp[-1], dp[-2])
