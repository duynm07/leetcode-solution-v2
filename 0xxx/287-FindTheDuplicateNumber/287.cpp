#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int ans;
        for (int i : nums) {
            nums[abs(i)] = -nums[abs(i)];
            if (nums[abs(i)] > 0) {
                ans = abs(i);
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);
    }
};