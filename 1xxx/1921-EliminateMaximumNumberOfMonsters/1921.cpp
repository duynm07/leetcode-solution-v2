#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        for (int i = 0; i < dist.size(); i++)
            speed[i] = dist[i] / speed[i] + (dist[i] % speed[i] != 0);

        sort(speed.begin(), speed.end());

        int ans = 0;
        while (ans < speed.size() && ans < speed[ans])
            ans++;

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}