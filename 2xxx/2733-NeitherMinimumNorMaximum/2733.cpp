#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int> &nums) {
        if (nums.size() <= 2)
            return -1;
            
        if (nums[0] > nums[1] && nums[0] > nums[2])
            return max(nums[1], nums[2]);

        if (nums[1] > nums[0] && nums[1] > nums[2])
            return max(nums[0], nums[2]);

        if (nums[2] > nums[1] && nums[2] > nums[0])
            return max(nums[1], nums[0]);
    }
};