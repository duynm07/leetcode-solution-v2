#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        vector<int> min_to;
        min_to.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            min_to.push_back(min(min_to[i - 1], nums[i]));

        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= min_to[i])
                st.pop();
            if (!st.empty() && nums[i] > min_to[i] && nums[i] > st.top())
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.find132pattern(nums);

    return 0;
}