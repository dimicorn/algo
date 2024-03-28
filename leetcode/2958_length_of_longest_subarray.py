class Solution:
    def maxSubarrayLength(self, nums: list, k: int) -> int:
        hash_map = {}
        l, r = 0, 0
        n = len(nums)
        res = 0
        while l <= r and r < n:
            if nums[r] not in hash_map:
                hash_map[nums[r]] = 1
                r += 1
            elif hash_map[nums[r]] < k:
                hash_map[nums[r]] += 1
                r += 1
            else:
                while hash_map[nums[r]] == k:
                    hash_map[nums[l]] -= 1
                    l += 1
            res = max(r - l, res)
        return res

nums = [1,2,3,1,2,3,1,2]
k = 2

sol = Solution()
res = sol.maxSubarrayLength(nums, k)
print(res)
