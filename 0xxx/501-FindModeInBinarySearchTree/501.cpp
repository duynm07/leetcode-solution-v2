#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *u, vector<int> &ans, int currNum, int currCount, int &maxCount) {
        if (u->val == currNum)
            currCount++;
        else {
            currCount = 1;
            currNum = u->val;
        }

        if (currCount == maxCount) {
            ans.push_back(currNum);
        } else if (currCount > maxCount)
            ans = {currNum};
    }
    // vector<int> findMode(TreeNode *root) {
    //     unordered_map<int, int> counter;
    //     int maxCount = 0;
    //     dfs(root, counter, maxCount);

    //     vector<int> ans;
    //     for (int i = -100000; i <= 100000; i++) {
    //         if (counter[i] == maxCount)
    //             ans.push_back(i);
    //     }

    //     return ans;
    // }
};

int main() {
    Solution sol = Solution();

    return 0;
}