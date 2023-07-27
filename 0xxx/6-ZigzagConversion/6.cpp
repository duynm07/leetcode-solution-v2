#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1)
            return s;
        vector<char> ans;
        for (int i = 1; i <= numRows; i++) {
            int index = i;
            while (index <= n) {
                ans.push_back(s[index - 1]);
                if (i != 1 && i != numRows && index + 2 * (numRows - i) <= n) {
                    ans.push_back(s[index + 2 * (numRows - i) - 1]);
                }
                index += 2 * (numRows - 1);
            }
        }

        return string(ans.begin(), ans.end());
    }
};

int main() {
    Solution solution = Solution();
    string s = "A";

    string ans = solution.convert("ABCDEFGHIJKLMN", 3);

    cout << ans;

    return 0;
}