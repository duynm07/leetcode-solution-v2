#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        vector<int> dp(n, 0);
        int ans = 1;
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << sol.findLongestChain(pairs);
}