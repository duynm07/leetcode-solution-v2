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
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        int currCount = 0;
        int rowStopCount = 1;
        int currRowMax = INT_MIN;

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            currRowMax = max(currRowMax, node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

            currCount++;
            if (currCount == rowStopCount) {
                ans.push_back(currRowMax);
                currRowMax = INT_MIN;
                rowStopCount += q.size();
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}