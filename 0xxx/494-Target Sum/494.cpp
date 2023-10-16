#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target, int i = 0) {
        return i == nums.size() ? target == 0 : findTargetSumWays(nums, target + nums[i], i + 1) + findTargetSumWays(nums, target - nums[i], i + 1);
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}