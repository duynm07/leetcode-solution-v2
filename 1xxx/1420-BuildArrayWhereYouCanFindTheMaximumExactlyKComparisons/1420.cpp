#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp(int i, int maxValue, int remainCost, int m, int n, vector<vector<vector<int>>> &memo) {
        if (i == n)
            return remainCost == 0;
        if (remainCost < 0)
            return 0;

        if (memo[i][maxValue][remainCost] >= 0)
            return memo[i][maxValue][remainCost];

        int ans = ((long long)maxValue * dp(i + 1, maxValue, remainCost, m, n, memo)) % MOD;
        for (int value = maxValue + 1; value <= m; value++) {
            ans = (ans + dp(i + 1, value, remainCost - 1, m, n, memo)) % MOD;
        }
        return memo[i][maxValue][remainCost] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return dp(0, 0, k, m, n, memo);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.numOfArrays(2, 3, 1);

    return 0;
}