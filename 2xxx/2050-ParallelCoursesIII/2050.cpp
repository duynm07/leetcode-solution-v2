#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        vector<int> countPrerequisite(n + 1, 0);
        vector<vector<int>> nextCourse(n + 1, vector<int>());
        for (int i = 0; i < relations.size(); i++) {
            countPrerequisite[relations[i][1]]++;
            nextCourse[relations[i][0]].push_back(relations[i][1]);
        }

        vector<int> dp(n + 1, 0);
        queue<int> q;

        int ans = 0;
        for (int u = 1; u <= n; u++) {
            if (countPrerequisite[u] == 0) {
                dp[u] = time[u - 1];
                ans = max(ans, dp[u]);
                q.push(u);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : nextCourse[u]) {
                dp[v] = max(dp[v], dp[u] + time[v - 1]);
                ans = max(ans, dp[v]);
                countPrerequisite[v]--;
                if (countPrerequisite[v] == 0)
                    q.push(v);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> relations = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time = {1, 2, 3, 4, 5};

    cout << sol.minimumTime(12, relations, time);

    return 0;
}