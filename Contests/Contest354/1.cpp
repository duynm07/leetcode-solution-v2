#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        k *= 2;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (nums[i] - nums[left] > k)
                left++;
            while (right < n && nums[right] - nums[i] <= k)
                right++;
            cout << nums[i] << " " << left << " " << right << endl;
            ans = max(ans, right - left);
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {4,6,1,2};
    cout << sol.maximumBeauty(nums, 2);
}