#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int previ = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > 0 && nums[i] == previ)
                continue;
            previ = nums[i];
            int prevj = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == prevj)
                    continue;
                prevj = nums[j];
                int target = -(nums[i] + nums[j]);
                int first = j + 1;
                int last = nums.size() - 1;
                while (first <= last) {
                    int mid = (first + last) / 2;
                    if (nums[mid] == target) {
                        ans.push_back({nums[i], nums[j], nums[mid]});
                        break;
                    } else if (nums[mid] < target)
                        first = mid + 1;
                    else
                        last = mid - 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {-4, -2, -2, -2, -2, 0, 2, 2, 2, 4, 4, 4, 6, 6, 8};
    vector<vector<int>> ans = sol.threeSum(nums);
    for (vector<int> triplet : ans) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }
}