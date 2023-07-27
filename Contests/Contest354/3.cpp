#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int> &nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        int dominant;
        int maxFreq = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            freq[num] = freq.count(num) == 0 ? 1 : freq[num] + 1;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                dominant = num;
            }
        }

        int freqLeft = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant)
                freqLeft++;
            int freqRight = maxFreq - freqLeft;
            if (freqLeft * 2 > i + 1 && freqRight * 2 > n - (i + 1))
                return i;
        }

        return -1;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {1, 2, 2, 2};
    // vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    vector<int> nums = {3, 3, 3, 3, 7, 2, 2};
    cout << sol.minimumIndex(nums) << endl;
}