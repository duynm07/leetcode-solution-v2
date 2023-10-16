#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        if (words.size() <= 1)
            return words.size();
        sort(words.begin(), words.end(), [](const string &word1, const string &word2) { return word1.size() < word2.size(); });
        if (words[0].length() == words[words.size() - 1].length())
            return 1;

        unordered_map<string, int> dp;
        int ans = 0;
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                temp.erase(i, 1);
                if (dp.count(temp) > 0)
                    dp[word] = max(dp[word], dp[temp] + 1);
            }
            ans = max(ans, dp[word]);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    // vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << sol.longestStrChain(words);

    return 0;
}