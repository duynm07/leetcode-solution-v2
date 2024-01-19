#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int count(int n, int k, int target, vector<vector<int>> &memo) {
        if (target <= 0 || n < 1)
            return 0;
        if (n == 1)
            return target <= k;
        if (memo[n][target] >= 0)
            return memo[n][target];

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = ((long long)ans + count(n - 1, k, target - i, memo)) % MOD;
        }

        return memo[n][target] = ans;
    };

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return count(n, k, target, memo);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.numRollsToTarget(2, 6, 7);

    return 0;
}