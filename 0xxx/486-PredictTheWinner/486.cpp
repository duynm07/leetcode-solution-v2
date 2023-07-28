#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int check(vector<int> &nums, int l, int r, int s) {
        if (l == r)
            return nums[l];
        return max(s - check(nums, l + 1, r, s - nums[l]), s - check(nums, l, r - 1, s - nums[r]));
    }
    bool PredictTheWinner(vector<int> &nums) {
        int totalScore = 0;
        for (int num : nums)
            totalScore += num;
        int p1Score = check(nums, 0, nums.size() - 1, totalScore);
        return p1Score >= totalScore - p1Score;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 5, 233, 7};
    cout << sol.PredictTheWinner(nums);
}