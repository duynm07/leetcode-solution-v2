#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> st;
        for (int ast : asteroids)
            if (ast > 0 || st.empty() || st.top() < 0)
                st.push(ast);
            else {
                bool destroyed = false;
                while (st.top() > 0 && st.top() <= -ast) {
                    int lastRight = st.top();
                    st.pop();
                    if (st.empty() || lastRight + ast == 0) {
                        if (lastRight + ast == 0)
                            destroyed = true;
                        break;
                    }
                }
                if (!destroyed && (st.empty() || st.top() < 0))
                    st.push(ast);
            }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        for (int i = 0; i < ans.size() / 2; i++) {
            int temp = ans[i];
            ans[i] = ans[ans.size() - i - 1];
            ans[ans.size() - i - 1] = temp;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> ats = {5, 10, -5};
    // vector<int> ats = {8, -8};
    // vector<int> ats = {10, 2, -5};
    // vector<int> ats = {-3, 5, 10, -5};
    vector<int> ats = {-2, -2, 1, -2};
    vector<int> ans = sol.asteroidCollision(ats);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}