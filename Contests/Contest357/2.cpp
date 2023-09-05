#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>> &dp, vector<int> &nums, vector<int> &ps, int m, int start, int end) {
        if (dp[start][end] >= 0)
            return dp[start][end];
        if (end - start < 2) {
            dp[start][end] = 1;
            return true;
        }
        if (ps[end + 1] - ps[start] < m) {
            dp[start][end] = 0;
            return false;
        }
        for (int i = start; i < end; i++)
            if (check(dp, nums, ps, m, start, i) && check(dp, nums, ps, m, i + 1, end)) {
                dp[start][end] = 1;
                return true;
            }
        dp[start][end] = 0;
        return false;
    }

    bool canSplitArray(vector<int> &nums, int m) {
        int n = nums.size();
        if (n <= 2)
            return true;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> ps;
        ps.push_back(0);
        for (int i = 0; i < n; i++)
            ps.push_back(ps[i] + nums[i]);
        return check(dp, nums, ps, m, 0, n - 1);
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {2, 2, 1};
    // vector<int> nums = {2, 1, 3};
    // vector<int> nums = {2, 3, 3, 2, 3};
    vector<int> nums = {1, 1};
    cout << sol.canSplitArray(nums, 3);
}