#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums, int li, int ri) {
        if (ri - li < 2)
            return true;

        vector<int> temp;
        for (int i = li; i <= ri; i++) {
            temp.push_back(nums[i]);
        }

        sort(temp.begin(), temp.end());

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] - temp[i - 1] != temp[1] - temp[0])
                return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            ans.push_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}