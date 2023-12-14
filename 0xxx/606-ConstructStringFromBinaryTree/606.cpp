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
    void dfs(TreeNode *u, string &str) {
        if (u == nullptr)
            return;
        str += to_string(u->val);
        if (u->left || u->right) {
            str += "(";
            dfs(u->left, str);
            str += ")";
        }
        if (u->right) {
            str += "(";
            dfs(u->right, str);
            str += ")";
        }
    }
    string tree2str(TreeNode *root) {
        string ans = "";
        dfs(root, ans);
        return ans.substr(1, ans.length() - 2);
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}