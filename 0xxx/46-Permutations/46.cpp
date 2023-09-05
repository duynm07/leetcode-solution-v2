#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void build(vector<int> &nums, vector<vector<int>> &ans, vector<int> &x, vector<bool> &flag, int i) {
        int n = nums.size();
        if (i == n) {
            vector<int> perm;
            for (int xi : x) {
                perm.push_back(nums[xi]);
            }
            ans.push_back(perm);
            return;
        }
        for (int j = 0; j < n; j++)
            if (flag[j]) {
                x[i] = j;
                flag[j] = false;
                build(nums, ans, x, flag, i + 1);
                flag[j] = true;
            }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> x(n);
        vector<bool> flag(n, true);
        build(nums, ans, x, flag, 0);
        return ans;
    }
};