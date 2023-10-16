#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;

        for (int n : nums) {
            if (n == candidate1)
                count1++;
            else if (n == candidate2)
                count2++;
            else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int n : nums) {
            if (n == candidate1)
                count1++;
            if (n == candidate2)
                count2++;
        }
        if (count1 > nums.size() / 3 && count2 > nums.size() / 3)
            return {candidate1, candidate2};
        if (count1 > nums.size() / 3)
            return {candidate1};
        if (count2 > nums.size() / 3)
            return {candidate2};
        return {};
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 2, 1, 2, 45, 5, 1, 2};
    vector<int> ans = sol.majorityElement(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}