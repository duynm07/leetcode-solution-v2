#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> ans = generate(numRows - 1);
        vector<int> row = {1};
        for (int i = 1; i < ans.back().size(); i++)
            row.push_back(ans.back()[i - 1] + ans.back()[i]);
        row.push_back(1);
        ans.push_back(row);
        return ans;
    }
};