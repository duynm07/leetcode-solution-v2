#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        vector<int> ps;
        ps.push_back(0);
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                ps.push_back(ps[i] + 1);
            else
                ps.push_back(ps[i]);

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len;
                int count = ps[j] - ps[i];
                if (count == k) {
                    string substr = s.substr(i, len);
                    if (ans.length() == 0 || substr < ans)
                        ans = substr;
                }
            }
            if (ans.length() > 0)
                break;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}