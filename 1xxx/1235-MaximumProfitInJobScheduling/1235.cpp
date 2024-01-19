#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findLatestIndexNotOverlap(vector<tuple<int, int, int>> &jobs, int l, int h, int startTime) {
        int ans = -1;
        int first = l;
        int last = h;
        while (first <= last) {
            int mid = (first + last) / 2;
            int eT = get<0>(jobs[mid]);
            if (eT <= startTime) {
                ans = mid;
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(jobs.size());
        dp[0] = get<2>(jobs[0]);

        for (int i = 1; i < jobs.size(); i++) {
            int eT = get<0>(jobs[i]);
            int sT = get<1>(jobs[i]);
            int prf = get<2>(jobs[i]);

            dp[i] = max(dp[i - 1], prf);

            int latestIndexNotOverlap = findLatestIndexNotOverlap(jobs, 0, i - 1, sT);
            if (latestIndexNotOverlap >= 0) {
                dp[i] = max(dp[i], dp[latestIndexNotOverlap] + prf);
            }
        }

        return dp[jobs.size() - 1];
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}