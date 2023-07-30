#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &dp, string &s, int left, int right) {
        if (dp[left][right] >= 0)
            return dp[left][right];

        if (left == right) {
            dp[left][right] = 0;
            return 0;
        }

        int j = -1;
        for (int i = left; i < right && j < 0; i++)
            if (s[i] != s[right])
                j = i;

        if (j < 0) {
            dp[left][right] = 0;
            return 0;
        }

        int ans = s.length();
        for (int i = j; i < right; i++)
            ans = min(ans, 1 + solve(dp, s, j, i) + solve(dp, s, i + 1, right));

        dp[left][right] = ans;
        return ans;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 1 + solve(dp, s, 0, n - 1);
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.strangePrinter("qwertzuiopasdfghjklyxcvbnmzuiopasdfghjklqwertyuioxcvbnmzuiopasxcvbnmkqwertyuiopasdfghjklmxcvbnkqwertyuiopasdfghjklzxcvbnm");
}