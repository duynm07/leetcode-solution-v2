#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void tryDistributeCookies(vector<int> &cookies, vector<int> &x, vector<int> &counts, int &maxCount, int &ans, int i, int k) {
        for (int j = 0; j < k; j++) {
            x[i] = j;

            if (counts[j] + cookies[i] > ans)
                continue;

            counts[j] += cookies[i];
            int oldMaxCount = maxCount;
            maxCount = max(maxCount, counts[j]);

            if (i == cookies.size() - 1) {
                if (maxCount < ans)
                    ans = maxCount;
                ans = min(ans, maxCount);
            } else
                tryDistributeCookies(cookies, x, counts, maxCount, ans, i + 1, k);

            counts[j] -= cookies[i];
            maxCount = oldMaxCount;
        }
    }
    int distributeCookies(vector<int> &cookies, int k) {
        int n = cookies.size();

        if (k == n) {
            int ans = 0;
            for (int ck : cookies)
                ans = max(ans, ck);
            return ans;
        }

        vector<int> x(n);
        vector<int> counts(k, 0);
        int maxCount = 0;
        int ans = 1e6;

        tryDistributeCookies(cookies, x, counts, maxCount, ans, 0, k);

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> cookies = {8, 15, 10, 20, 8};
    vector<int> cookies = {6, 1, 3, 2, 2, 4, 1, 2};
    cout << sol.distributeCookies(cookies, 8);
}