#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int n) {
        int m = ceil((double)n / 25);
        if (m > 200)
            return 1;

        // unordered_map<int, unordered_map<int, double>> dp;
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, 0));
        dp[0][0] = 0.5;
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] + dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) / 4;

        return dp[m][m];
    }
};