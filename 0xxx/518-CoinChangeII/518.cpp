#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0)
            return 1;

        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i <= amount; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = i % coins[j] == 0;
                    continue;
                }
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j])
                    dp[i][j] += dp[i - coins[j]][j];
            }

        // for (int i = 0; i <= amount; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[amount][n - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> coins = {1, 2, 5};
    cout << sol.change(5, coins);
}