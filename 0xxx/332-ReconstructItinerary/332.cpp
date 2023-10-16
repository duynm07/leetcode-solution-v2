#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjs;
        for (vector<string> ticket : tickets) {
            if (adjs.count(ticket[0]) == 0)
                adjs[ticket[0]] = priority_queue<string, vector<string>, greater<string>>();
            adjs[ticket[0]].push(ticket[1]);
        }

        stack<string> airportStack;
        vector<string> ans;

        airportStack.push("JFK");

        while (!airportStack.empty()) {
            string u = airportStack.top();
            if (adjs[u].empty()) {
                ans.push_back(u);
                airportStack.pop();
            } else {
                string v = adjs[u].top();
                adjs[u].pop();
                airportStack.push(v);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}