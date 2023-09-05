#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i])
                st.pop();

            if (st.empty())
                ans[i] = prices[i];
            else
                ans[i] = prices[i] - st.top();

            st.push(prices[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> ans = sol.finalPrices(prices);
}