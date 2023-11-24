#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> startIndex(26, -1), endIndex(26, -1);

        for (int i = 0; i < s.length(); i++) {
            if (startIndex[s[i] - 'a'] < 0)
                startIndex[s[i] - 'a'] = i + 1;
            endIndex[s[i] - 'a'] = i + 1;
        }

        vector<vector<int>> ps(26);
        for (int ch = 'a'; ch <= 'z'; ch++) {
            ps[ch - 'a'].push_back(0);
            for (int i = 0; i < s.length(); i++) {
                ps[ch - 'a'].push_back(s[i] == ch ? ps[ch - 'a'][i] + 1 : ps[ch - 'a'][i]);
            }
        }

        int ans = 0;
        for (int ch = 'a'; ch <= 'z'; ch++) {
            int start = startIndex[ch - 'a'];
            int end = endIndex[ch - 'a'];
            if (end - start < 2)
                continue;
            for (int mid = 'a'; mid <= 'z'; mid++) {
                if (ps[mid - 'a'][end - 1] - ps[mid - 'a'][start] > 0)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.countPalindromicSubsequence("bbcbaba");

    return 0;
}