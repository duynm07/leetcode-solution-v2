#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adjs(numCourses, vector<int>());
        vector<int> countPre(numCourses, 0);
        for (vector<int> preq : prerequisites) {
            int u = preq[1];
            int v = preq[0];
            adjs[u].push_back(v);
            countPre[v]++;
        }

        queue<int> q;
        for (int u = 0; u < numCourses; u++)
            if (countPre[u] == 0)
                q.push(u);

        int countLearned = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            countLearned++;
            for (int v : adjs[u]) {
                countPre[v]--;
                if (countPre[v] == 0)
                    q.push(v);
            }
        }

        return countLearned == numCourses;
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> prerequisites = {{1, 0}, {1, 2}, {0, 1}};

    cout << sol.canFinish(3, prerequisites);

    return 0;
}