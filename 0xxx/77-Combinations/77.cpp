#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void build(vector<vector<int>> &ans, vector<int> &x, vector<bool> &flag, int i, int k, int n) {
        if (i == k) {
            ans.push_back(x);
            return;
        }
        for (int j = i == 0 ? 1 : x[i - 1] + 1; j <= n; j++)
            if (flag[j]) {
                x[i] = j;
                flag[j] = false;
                build(ans, x, flag, i + 1, k, n);
                flag[j] = true;
            }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> x(k);
        vector<bool> flag(n + 1, true);
        build(ans, x, flag, 0, k, n);
        return ans;
    }
};