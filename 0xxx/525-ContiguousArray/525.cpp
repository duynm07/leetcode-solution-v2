#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {

        int n = nums.size();

        vector<int> prefixSum;
        prefixSum.push_back(0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                prefixSum.push_back(prefixSum[i] + 1);
            else
                prefixSum.push_back(prefixSum[i] - 1);
        }

        unordered_map<int, int> pos;
        int maxLength = 0;

        pos[0] = 0;
        int maxLength = 0;
        for (int i = 1; i <= n; i++) {
            if (pos.count(prefixSum[i]) > 0) {
                maxLength = max(maxLength, i - pos[prefixSum[i]]);
            } else {
                pos[prefixSum[i]] = i;
            }
        }

        return maxLength;
    }
};