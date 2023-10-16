#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(string s, int i, int j, vector<vector<int>> &memo) {
        if (j - i < 2)
            return s[i] == s[j];
        if (memo[i][j] >= 0)
            return memo[i][j];
        return memo[i][j] = s[i] == s[j] ? check(s, i + 1, j - 1, memo) : false;
    }
    string longestPalindrome(string s) {
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
        for (int l = s.length(); l > 0; l--) {
            for (int i = 0; i < s.length() - l + 1; i++) {
                if (check(s, i, i + l - 1, memo))
                    return s.substr(i, l);
            }
        }
        return to_string(s[0]);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.longestPalindrome("babad") << endl;
    cout << sol.longestPalindrome("cbbd") << endl;
    cout << sol.longestPalindrome("klszjdghsdfnbvuierhgioserghsdfkgilsdfhvnklsdfjvasdjkhfdlfjjkzxfhvlwvnsdlkfjvhseliuhgejnglskdjfhlsdufhvlksjdnflgiudhslkvjsdnflvuhwelgjhlshilserughlsdjkfviosdfhvklsdfhjvosdfvhpoefjghloisdfjhvjklsdfhvbuilsdrhglskdfjvhuilsdfvhlsdkgh") << endl;

    return 0;
}