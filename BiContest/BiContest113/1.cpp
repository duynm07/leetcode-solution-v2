#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                ans = n - i;
                break;
            }
        }
        if (ans == 0)
            return ans;
        if (nums[n - 1] > nums[0])
            return -1;
        for (int i = 0; i < n - ans - 1; i++) {
            if (nums[i] > nums[i + 1])
                return -1;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    vector<int> nums = {63, 51, 65, 87, 6, 17, 32, 14, 42, 46};
    cout << sol.minimumRightShifts(nums);

    return 0;
}