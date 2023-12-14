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
    vector<int> dfs(TreeNode *u, vector<int> &ans) {
        if (u != nullptr) {
            dfs(u->left, ans);
            ans.push_back(u->val);
            dfs(u->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}