#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1; // Check the LSB and add it to the count if it's 1
            num >>= 1;        // Right-shift the number to check the next bit
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (countSetBits(i) == k)
                ans += nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}