#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int left = 0;
        int ans = 0;
        int countZero = 0;
        bool containZero = false;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                containZero = true;
                countZero++;
                while (countZero == 2) {
                    if (nums[left] == 0)
                        countZero--;
                    left++;
                }
            }
            ans = max(ans, right - left);
        }

        return containZero ? ans : n - 1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << sol.longestSubarray(nums);
}