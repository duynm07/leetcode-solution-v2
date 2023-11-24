#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &f, bool &check) {
        if (!check)
            return;
        for (int v : {leftChild[u], rightChild[u]}) {
            if (v < 0)
                continue;
            if (!f[v]) {
                check = false;
                return;
            }
            f[v] = false;
            dfs(v, leftChild, rightChild, f, check);
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        // Find root
        vector<int> countInEdge(n, 0);
        vector<int> countOutEdge(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0) {
                countOutEdge[i]++;
                countInEdge[leftChild[i]]++;
            }
            if (rightChild[i] >= 0) {
                countOutEdge[i]++;
                countInEdge[rightChild[i]]++;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (countInEdge[i] > 1 || countOutEdge[i] > 2)
                return false;
            if (countInEdge[i] == 0) {
                if (root >= 0)
                    return false;
                else
                    root = i;
            }
        }
        if (root < 0)
            return false;

        // Check cycle
        vector<bool> f(n, true);
        f[root] = false;
        bool checkCycle = true;
        dfs(root, leftChild, rightChild, f, checkCycle);
        if (!checkCycle)
            return false;

        // Check connected
        for (int i = 0; i < n; i++) {
            if (f[i])
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}