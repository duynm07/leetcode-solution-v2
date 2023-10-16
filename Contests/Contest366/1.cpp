#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater());

        int ans = 0;
        for (int i = 0; i < processorTime.size(); i++) {
            int time = processorTime[i] + max(tasks[4 * i], max(tasks[4 * i + 1], max(tasks[4 * i + 2], tasks[4 * i + 3])));
            ans = max(ans, time);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}