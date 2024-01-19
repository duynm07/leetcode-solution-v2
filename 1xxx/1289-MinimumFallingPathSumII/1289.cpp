#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    dp[i][j] = INT_MAX;
                    for (int k = 0; k < n; k++) {
                        if (k != j) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + matrix[i][j]);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}