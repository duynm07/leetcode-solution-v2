#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate)
                count++;
            else if (count == 0) {
                count = 1;
                candidate = nums[i];
            } else
                count--;
        }
        return candidate;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}