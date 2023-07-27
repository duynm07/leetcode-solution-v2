#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int> &nums) {
        int n = nums.size();
        long long ans = 0;

        multiset<long long> ms;

        int left = 0;
        for (int right = 0; right < n; right++) {
            ms.insert(nums[right]);
            while (*ms.rbegin() - *ms.begin() > 2) {
                auto it = ms.find(nums[left]);
                ms.erase(it);
                left++;
            }
            ans += right - left + 1;
        }

        return ans;
    }
};