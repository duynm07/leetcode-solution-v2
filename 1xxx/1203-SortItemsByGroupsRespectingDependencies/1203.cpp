#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topoOrder(int n, unordered_map<int, set<int>> &adjs) {
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++)
            if (adjs.count(u))
                for (int v : adjs[u])
                    indegree[v]++;

        queue<int> S;
        for (int u = 0; u < n; u++)
            if (indegree[u] == 0)
                S.push(u);

        vector<int> ans;
        while (!S.empty()) {
            int u = S.front();
            S.pop();

            ans.push_back(u);

            if (adjs.count(u) == 0)
                continue;

            for (int v : adjs[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    S.push(v);
            }
        }

        return ans.size() == n ? ans : vector<int>(0);
    }
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {

        unordered_map<int, set<int>> itemAdjs;

        for (int v = 0; v < beforeItems.size(); v++) {
            for (int u : beforeItems[v]) {
                if (itemAdjs.count(u) == 0)
                    itemAdjs[u] = {};
                itemAdjs[u].insert(v);
            }
        }

        vector<int> itemOrders = topoOrder(n, itemAdjs);
        if (itemOrders.size() == 0)
            return itemOrders;

        for (int i = 0; i < group.size(); i++)
            if (group[i] < 0)
                group[i] = m++;

        vector<vector<int>> groups(m, vector<int>(0));
        for (int u : itemOrders)
            groups[group[u]].push_back(u);

        unordered_map<int, set<int>> groupAdjs;
        for (int v = 0; v < beforeItems.size(); v++) {
            int groupV = group[v];
            for (int u : beforeItems[v]) {
                int groupU = group[u];
                if (groupU == groupV)
                    continue;
                if (groupAdjs.count(groupU) == 0)
                    groupAdjs[groupU] = {};
                groupAdjs[groupU].insert(groupV);
            }
        }
        vector<int> groupOrders = topoOrder(m, groupAdjs);
        if (groupOrders.size() == 0)
            return groupOrders;

        vector<int> ans;

        for (int i = 0; i < groupOrders.size(); i++) {
            for (int u : groups[groupOrders[i]])
                ans.push_back(u);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    vector<int> ans = sol.sortItems(8, 2, group, beforeItems);
    for (int an : ans)
        cout << an << " ";
}