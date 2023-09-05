#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int left = 0;
        unordered_map<int, int> counter;
        int currSum = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (counter.count(nums[right]) == 0)
                counter[nums[right]] = 0;
            counter[nums[right]]++;
            currSum += nums[right];
            while (counter[nums[right]] > 1) {
                currSum -= nums[left];
                counter[nums[left]]--;
                left++;
            }
            ans = max(ans, currSum);
        }

        return ans;
    }
};