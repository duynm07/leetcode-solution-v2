#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        unordered_map<int, int> count;
        for (int num : nums)
            count[num] = count.count(num) == 0 ? 1 : count[num] + 1;

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
        }
        
    }
};