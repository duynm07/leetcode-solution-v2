#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        vector<pair<int, int>> peopleIndex;
        for (int i = 0; i < people.size(); i++)
            peopleIndex.push_back({people[i], i});

        sort(flowers.begin(), flowers.end());
        sort(peopleIndex.begin(), peopleIndex.end());

        vector<int> ans(people.size());
        int index = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (pair<int, int> person : peopleIndex) {
            int p = person.first;
            int i = person.second;
            while (index < flowers.size() && flowers[index][0] <= p)
                pq.push(flowers[index++][1]);
            while (!pq.empty() && pq.top() < p)
                pq.pop();
            ans[i] = pq.size();
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}