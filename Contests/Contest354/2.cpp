#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] - nums[left] <= 2 * k)
                right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {4, 6, 1, 2};
    vector<int> nums = {49, 26};
    cout << sol.maximumBeauty(nums, 12);
}