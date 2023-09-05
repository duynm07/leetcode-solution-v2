#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int computeSumASCII(string &s, int ind) {
        int ans = 0;
        for (int i = 0; i <= ind; i++)
            ans += s[i];

        return ans;
    }
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
    int computeCost(vector<vector<int>> &dp, string &s1, string &s2, int i, int j) {
        if (i < 0)
            return computeSumASCII(s2, j);
        if (j < 0)
            return computeSumASCII(s1, i);

        if (dp[i][j] >= 0)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = computeCost(dp, s1, s2, i - 1, j - 1);
        } else {
            dp[i][j] = min3((int)s1[i] + computeCost(dp, s1, s2, i - 1, j), (int)s2[j] + computeCost(dp, s1, s2, i, j - 1), (int)s1[i] + s2[j] + computeCost(dp, s1, s2, i - 1, j - 1));
        }
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return computeCost(dp, s1, s2, s1.length() - 1, s2.length() - 1);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.minimumDeleteSum("ihlnqpdwqgcd", "mgrumwmpjedv");
}