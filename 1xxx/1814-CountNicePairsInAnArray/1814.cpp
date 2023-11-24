#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countNicePairs(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int reverse = 0;
            int temp = nums[i];
            while (nums[i]) {
                reverse = reverse * 10 + nums[i] % 10;
                nums[i] /= 10;
            }
            nums[i] = temp - reverse;
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            if (right + 1 == nums.size() || nums[right + 1] != nums[right]) {
                while (left < right && nums[left] < nums[right])
                    left++;
                ans += (long long)(right - left + 1) * (right - left) / 2;
                ans = ans % MOD;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {13, 10, 35, 24, 76};

    cout << sol.countNicePairs(nums);

    return 0;
}