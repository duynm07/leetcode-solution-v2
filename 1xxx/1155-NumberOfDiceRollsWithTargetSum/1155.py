from functools import lru_cache


class Solution:
    MOD = 10**9 + 7

    def count(self, n, k, target, memo):
        if target <= 0 or n < 1:
            return 0
        if n == 1:
            return 1 if target <= k else 0
            
        if memo[n][target] >= 0:
            return memo[n][target]

        ans = 0
        for i in range(1, k + 1):
            ans = (ans + self.count(n - 1, k, target - i, memo)) % self.MOD

        memo[n][target] = ans
        return ans

    def numRollsToTarget(self, n, k, target):
        memo = [[-1] * (target + 1) for _ in range(n + 1)]
        return self.count(n, k, target, memo)
