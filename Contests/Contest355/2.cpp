#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> tempArray;
        long long current = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i - 1])
                current += nums[i];
            else {
                tempArray.push_back(current);
                current = nums[i];
            }
        }
        tempArray.push_back(current);

        long long ans = 0;
        current = tempArray[tempArray.size() - 1];
        for (int i = tempArray.size() - 2; i >= 0; i--) {
            if (tempArray[i] <= tempArray[i + 1])
                current += tempArray[i];
            else {
                ans = max(ans, current);
                current = tempArray[i];
            }
        }
        return max(ans, current);
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {2, 3, 7, 9, 3};
    vector<int> nums = {5, 3, 3};
    cout << sol.maxArrayValue(nums) << endl;
}