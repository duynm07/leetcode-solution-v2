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
    pair<int, int> treeInfo(TreeNode *u, int &ans) {
        if (u == nullptr)
            return {0, 0};

        pair<int, int> leftTreeInfo = treeInfo(u->left, ans);
        pair<int, int> rightTreeInfo = treeInfo(u->right, ans);

        int nodeCount = leftTreeInfo.first + rightTreeInfo.first + 1;
        int sumNode = leftTreeInfo.second + rightTreeInfo.second + u->val;

        if (sumNode / nodeCount == u->val)
            ans++;

        return {nodeCount, sumNode};
    }
 
    int averageOfSubtree(TreeNode *root) {
        int ans = 0;
        pair<int, int> info = treeInfo(root, ans);
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}