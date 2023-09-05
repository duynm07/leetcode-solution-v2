#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if (s3.length() != m + n)
            return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 0; i < m; i++) {
            dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
        }

        for (int i = 0; i < n; i++) {
            dp[0][i + 1] = dp[0][i] && s2[i] == s3[i];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // if (i == 2 && j == 4) cout << s3 << " " << dp[i - 1][j] << " " << dp[i][j - 1] << " " << s2[j - 1] << " " << s3[i + j - 1] << endl;
                dp[i][j] = (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) || (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
            }
        }

        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}