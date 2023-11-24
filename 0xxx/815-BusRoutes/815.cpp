#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasCommonNode(vector<int> routeu, vector<int> routev) {
        int i = 0;
        int j = 0;
        while (i < routeu.size() && j < routev.size()) {
            if (routeu[i] < routev[j])
                i++;
            else if (routeu[i] > routev[j])
                j++;
            else
                return true;
        }
        return false;
    }

    bool isContainNode(vector<int> route, int node) {
        int first = 0;
        int last = route.size() - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (route[mid] == node)
                return true;
            else if (route[mid] > node)
                last = mid - 1;
            else
                first = mid + 1;
        }

        return false;
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target)
            return 0;
        queue<int> q;
        vector<bool> free(routes.size(), true);
        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
            if (isContainNode(routes[i], source)) {
                q.push(i);
                free[i] = false;
            }
        }

        vector<vector<int>> adjs(routes.size());

        for (int u = 0; u < routes.size(); u++)
            for (int v = u + 1; v < routes.size(); v++)
                if (hasCommonNode(routes[u], routes[v])) {
                    adjs[u].push_back(v);
                    adjs[v].push_back(u);
                }

        int ans = 0;
        int countCurrentDepth = 0;
        while (!q.empty()) {
            if (countCurrentDepth == 0) {
                ans++;
                countCurrentDepth = q.size();
            }
            int u = q.front();
            if (isContainNode(routes[u], target))
                return ans;
            q.pop();
            countCurrentDepth--;
            for (int v : adjs[u]) {
                if (free[v]) {
                    free[v] = false;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}