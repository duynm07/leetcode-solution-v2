#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums, int p, int diff) {
        int countPair = 0;
        int index = 0;
        while (index < nums.size() - 1) {
            if (nums[index + 1] - nums[index] <= diff) {
                countPair++;
                index += 2;
            } else {
                index++;
            }
        }
        return countPair >= p;
    }

    int minimizeMax(vector<int> &nums, int p) {
        sort(nums.begin(), nums.end());

        int first = 0;
        int last = nums[nums.size() - 1] - nums[0];
        int ans = last;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (check(nums, p, mid)) {
                ans = mid;
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {10, 1, 2, 7, 1, 3};
    // vector<int> nums = {4, 2, 1, 2};
    vector<int> nums = {3, 4, 2, 3, 2, 1, 2}; // 1222334
    cout << sol.minimizeMax(nums, 3);
}