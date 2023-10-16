#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        long long targetSum = -x;
        for (int num : nums)
            targetSum += num;
        if (targetSum < 0)
            return -1;
        if (targetSum == 0)
            return nums.size();

        int currSum = 0;
        int left = 0;
        int maxLength = -1;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            while (currSum > targetSum)
                currSum -= nums[left++];
            if (currSum == targetSum)
                maxLength = max(maxLength, right - left + 1);
        }

        return maxLength < 0 ? -1 : nums.size() - maxLength;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 1, 4, 2, 3};
    cout << sol.minOperations(nums, 5);

    return 0;
}