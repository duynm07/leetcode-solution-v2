#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int tapStart = max(0, i - ranges[i]);
            int tapEnd = min(i + ranges[i], n);
            for (int j = tapStart; j <= tapEnd; j++)
                dp[tapEnd] = min(dp[tapEnd], dp[j] + 1);
        }

        return dp[n] > n + 1 ? -1 : dp[n];
    }
};