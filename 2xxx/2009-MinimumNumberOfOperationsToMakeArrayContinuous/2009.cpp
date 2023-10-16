#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        unordered_map<int, int> counter;

        int left = 0;
        int ans = n;
        int countUnique = 0;

        for (int right = 0; right < n; right++) {
            if (counter.count(nums[right]) == 0) {
                counter[nums[right]] = 1;
                countUnique++;
            } else {
                counter[nums[right]]++;
            }

            while (nums[right] - nums[left] > n - 1) {
                counter[nums[left]]--;
                if (counter[nums[left]] == 0)
                    countUnique--;
                left++;
            }

            // for (int i = left; i <= right; i++) {
            //     cout << nums[i] << " ";
            // }
            // cout << " - " << countUnique << endl;

            int nTrans = n - (right - left + 1) + (right - left + 1) - countUnique;
            ans = min(ans, nTrans);
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 98, 100, 5, 2, 34, 1, 2, 4, 5, 2, 4, 65, 543, 234, 5, 3456, 234, 12, 23, 5, 23, 7, 32, 3};
    cout << sol.minOperations(nums);

    return 0;
}