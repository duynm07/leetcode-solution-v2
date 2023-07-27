#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashTable;

        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(target - nums[i]) > 0)
                return {i, hashTable[target - nums[i]]};
            hashTable[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums{1, 2, 3, 4, 5};
    int target = 5;

    vector<int> ans = solution.twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}