#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void build(vector<vector<int>> &ans, vector<int> &x, vector<int> &candidates, int target) {
        if (target == 0) {
            ans.push_back(x);
            return;
        }
        int lastNum = x.size() == 0 ? 0 : x[x.size() - 1];
        for (int num : candidates) {
            if (num <= target && num >= lastNum) {
                x.push_back(num);
                build(ans, x, candidates, target - num);
                x.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> x;
        build(ans, x, candidates, target);
        return ans;
    }
};

void build(vector<int> &x, vector<int> &candidates, int target) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "- " << target << endl;

    if (target == 0) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    int lastNum = x.size() == 0 ? 0 : x[x.size() - 1];
    for (int num : candidates) {
        if (num <= target && num >= lastNum) {
            x.push_back(num);
            build(x, candidates, target - num);
            x.pop_back();
        }
    }
}

int main() {
    Solution sol = Solution();

    vector<int> candidates = {2, 3, 6, 7};
    vector<int> x;
    // build(x, candidates, 7);

    return 0;
}