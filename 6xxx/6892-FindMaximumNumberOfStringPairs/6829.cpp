#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string> &words) {
        int ans = 0;
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            string reversedStr;
            for (int j = word.length() - 1; j >= 0; --j) {
                reversedStr.push_back(word[j]);
            }
            if (hash.count(reversedStr) > 0) {
                ans++;
            };
            hash[word] = i;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
    int ans = sol.maximumNumberOfStringPairs(words);
    cout << ans;
}