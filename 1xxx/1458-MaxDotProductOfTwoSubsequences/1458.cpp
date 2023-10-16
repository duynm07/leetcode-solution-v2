#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, -INT_MAX));
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < m; i++)
            dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        for (int i = 1; i < n; i++)
            dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j - 1] + nums1[i] * nums2[j], max(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = max(dp[i][j], nums1[i] * nums2[j]);
            }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums1 = {-3, -8};
    vector<int> nums2 = {9, 2, 3, 7, -9};

    cout << sol.maxDotProduct(nums1, nums2);

    return 0;
}