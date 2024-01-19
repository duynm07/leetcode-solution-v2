#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int ans = 0;
        int currentTotal = 0;
        int currentMax = 0;
        for (int i = 0; i <= colors.length(); i++) {
            char color = colors[i];
            if (i > 0 && i < colors.length() && colors[i] == colors[i - 1]) {
                currentTotal += neededTime[i];
                currentMax = max(currentMax, neededTime[i]);
            } else {
                ans += currentTotal - currentMax;
                currentTotal = neededTime[i];
                currentMax = neededTime[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> needTime = {1, 2, 3, 4, 1};
    cout << sol.minCost("aabaa", needTime);

    return 0;
}