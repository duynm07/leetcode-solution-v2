#include <iostream>
#include <stdio.h>
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
    vector<TreeNode *> generateTrees(int end, int start = 1) {
        vector<TreeNode *> ans;

        if (start > end)
            return {nullptr};

        for (int i = start; i <= end; i++) {
            for (TreeNode *leftTree : generateTrees(i - 1, start))
                for (TreeNode *rightTree : generateTrees(end, i + 1))
                    ans.push_back(new TreeNode(i, leftTree, rightTree));
        }

        return ans;
    }
};