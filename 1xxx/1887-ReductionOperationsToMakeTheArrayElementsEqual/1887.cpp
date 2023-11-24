#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater());

        int ans = 0;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
                ans += i;

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}