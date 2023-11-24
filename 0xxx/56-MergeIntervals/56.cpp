#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });

        vector<vector<int>> ans;

        for (vector<int> segment : intervals) {
            if (ans.size() == 0)
                ans.push_back(segment);
            else {
                if (segment[0] <= ans[ans.size() - 1][1])
                    ans[ans.size() - 1][1] = max(segment[1], ans[ans.size() - 1][1]);
                else
                    ans.push_back(segment);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {2, 6}, {3, 5}, {8, 10}, {15, 18}, {0, 2}};
    vector<vector<int>> ans = sol.merge(intervals);
    for (vector<int> segment : ans) {
        cout << segment[0] << " " << segment[1] << endl;
    }

    return 0;
}