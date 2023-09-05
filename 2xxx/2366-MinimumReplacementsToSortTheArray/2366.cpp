#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            int num_elements = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            ans += num_elements - 1;
            nums[i] /= num_elements;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {3, 9, 3};
    cout << sol.minimumReplacement(nums);
}