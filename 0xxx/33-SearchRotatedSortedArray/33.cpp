#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (nums[0] == target)
            return 0;
        if (nums[n - 1] == target)
            return n - 1;
        int first = 0;
        int last = n - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (nums[mid] == target)
                return mid;
            if ((target > nums[mid] && (target <= nums[0] || nums[mid] >= nums[0])) || (target < nums[mid] && nums[mid] >= nums[0] && target <= nums[0]))
                first = mid + 1;
            else
                last = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {5, 1, 2, 3, 4};
    cout << sol.search(nums, 1);
}