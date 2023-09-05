#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums) {
        int NMAX = 2001;
        vector<bool> f(NMAX, false);
        int k = 0;
        for (int num : nums) {
            if (!f[num])
                k++;
            f[num] = true;
        }

        int left = 0;
        long long ans = 0;
        vector<int> cnt(NMAX, 0);
        int uniqueElementCount = 0;

        for (int right = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;
            if (cnt[nums[right]] == 1) {
                uniqueElementCount++;
            }
            // cout << "right = " << right << " - uniqueElementCount = " << uniqueElementCount << endl;
            while (uniqueElementCount > k) {
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0)
                    uniqueElementCount--;
                left++;
            }

            if (uniqueElementCount == k) {
                int tempLeft = left;
                while (uniqueElementCount == k) {
                    // cout << tempLeft << " " << right << endl;
                    ans++;
                    cnt[nums[tempLeft]]--;
                    if (cnt[nums[tempLeft]] == 0)
                        break;
                    tempLeft++;
                }

                for (int i = left; i <= tempLeft; i++)
                    cnt[nums[i]]++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 3, 1, 2, 2};
    // vector<int> nums = {5,5,5,5};
    // vector<int> nums = {459, 459, 962, 1579, 1435, 756, 1872, 1597};
    cout << sol.countCompleteSubarrays(nums);
}