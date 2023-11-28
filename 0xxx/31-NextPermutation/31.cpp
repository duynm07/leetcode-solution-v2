#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int index = nums.size() - 2;
        while (index >= 0 && nums[index] >= nums[index + 1])
            index--;
        if (index >= 0) {
            int currentMin = 101;
            int minIndex = -1;
            for (int i = index + 1; i < nums.size(); i++)
                if (nums[i] < currentMin && nums[i] > nums[index]) {
                    currentMin = nums[i];
                    minIndex = i;
                }
            nums[minIndex] = nums[index];
            nums[index] = currentMin;
        }
        sort(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {7, 8, 4, 5, 2};
    sol.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}