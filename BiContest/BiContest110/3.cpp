#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> f;
        for (int i = 0; i < n; i++) {
            if (f.count(nums[i]) == 0)
                f[nums[i]] = vector<int>();
            f[nums[i]].push_back(i);
        }

        int ans = n;
        for (const auto &pair : f) {
            vector<int> occurs = pair.second;
            int t = 0;
            int m = occurs.size();
            for (int i = 0; i < m - 1; i++) {
                t = max(t, (occurs[i + 1] - occurs[i]) / 2);
            }
            t = max(t, (n + occurs[0] - occurs[m - 1]) / 2);
            ans = min(ans, t);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 2, 1, 2};
    // vector<int> nums = {11, 4, 10};
    // vector<int> nums = {2, 1, 3, 3, 2};
    // vector<int> nums = {5, 5, 5, 5};
    // vector<int> nums = {8, 13, 3, 3};
    cout << sol.minimumSeconds(nums);
}