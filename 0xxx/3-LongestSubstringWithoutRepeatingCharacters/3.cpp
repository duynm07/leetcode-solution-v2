#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<int, int> f;
        int left = 0;
        for (int right = 0; right < n; right++) {
            f[s[right]] = f.count(s[right]) == 0 ? 1 : f[s[right]] + 1;
            if (f[s[right]] > 1) {
                // cout << left << " " << right << endl;
                ans = max(ans, right - left);
                while (left < right && s[left] != s[right])
                    f[s[left++]]--;
                if (s[left] == s[right]) f[s[left++]]--;
            }
        }
        ans = max(ans, n - left);
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.lengthOfLongestSubstring("abcabcbb");
    // cout << sol.lengthOfLongestSubstring("zxcvbnm");
}