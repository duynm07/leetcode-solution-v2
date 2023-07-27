#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int step, vector<int> &nums) {
        const int VMAX = 500;
        int ans = 0;
        int n = nums.size();
        vector<int> f(VMAX + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] - step < 0 || nums[i] - step > VMAX)
                f[nums[i]] = 1;
            else
                f[nums[i]] = max(f[nums[i]], f[nums[i] - step] + 1);
            ans = max(ans, f[nums[i]]);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << f[nums[i]] << " ";
        // }
        // cout << endl;
        return ans;
    }

    int longestArithSeqLength(vector<int> &nums) {
        int ans = 0;
        for (int step = -500; step <= 500; step++) {
            ans = max(ans, dp(step, nums));
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {9, 4, 7, 2, 10};
    vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
    int ans = sol.longestArithSeqLength(nums);
    cout << ans;
    // cout << sol.dp(3, nums);
}