#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int> &nums) {
        int right = 0;
        int count = 0;
        vector<bool> f(nums.size(), true);
        for (int left = 0; left < nums.size() && right < nums.size(); left++) {
            if (!f[left])
                continue;
            while (right < nums.size() && (!f[right] || nums[right] <= nums[left]))
                right++;
            if (right < nums.size()) {
                f[left] = false;
                f[right] = false;
                count += 2;
            }
        }
        return nums.size() - count;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {1, 3, 4, 9};
    vector<int> nums = {1, 1, 2};

    cout << sol.minLengthAfterRemovals(nums);

    return 0;
}