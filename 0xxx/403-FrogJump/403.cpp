#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canCross(vector<int> &stones) {
        int nStones = stones.size();
        if (nStones == 2)
            return stones[1] == 1;
        if (stones[1] != 1) return false; 
        vector<vector<bool>> f(nStones, vector<bool>(nStones + 1, false));
        f[1][1] = true;
        for (int i = 2; i < nStones; i++)
            for (int j = 1; j < i; j++) {
                int distance = stones[i] - stones[j];
                if (distance >= nStones)
                    continue;
                if (f[j][distance - 1] || f[j][distance] || f[j][distance + 1]) {
                    f[i][distance] = true;
                }
            }
        for (int d = 0; d < f[nStones - 1].size(); d++)
            if (f[nStones - 1][d])
                return true;
        return false;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    // vector<int> stones = {0, 1, 3, 6, 7};
    vector<int> stones = {0, 2, 4, 5, 6, 8, 9, 11, 14, 17, 18, 19, 20, 22, 23, 24, 25, 27, 30};
    cout << sol.canCross(stones);
}