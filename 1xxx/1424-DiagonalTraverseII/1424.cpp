#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                pq.push({i + j, j, nums[i][j]});
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(get<2>(pq.top()));
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}