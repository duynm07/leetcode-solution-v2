#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                counter[nums[i - k - 1]]--;
            }
            if (counter.count(nums[i]) == 0)
                counter[nums[i]] = 0;
            counter[nums[i]]++;
            if (counter[nums[i]] > 1)
                return true;
        }
        return false;
    }
};