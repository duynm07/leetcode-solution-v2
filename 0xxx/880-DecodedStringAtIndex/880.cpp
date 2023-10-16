#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int length = 0;
        if (length == 0) {
            for (char ch : s) {
                if (ch >= 'a' && ch <= 'z') {
                    length++;
                } else {
                    length *= ch - '0';
                }
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            char lastChar = s[i];
            if (k == length && lastChar >= 'a' && lastChar <= 'z')
                return string(1, lastChar);
            length = lastChar >= 'a' && lastChar <= 'z' ? length - 1 : length / (lastChar - '0');
            k = k % length;
            if (!k)
                k = length;
        }

        return "";
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.decodeAtIndex("a23", 6);

    return 0;
}