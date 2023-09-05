#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void build(string &digits, vector<string> &characters, vector<string> &ans, vector<char> &x, int i) {
        if (i == digits.length()) {
            string str(x.begin(), x.end());
            ans.push_back(str);
            return;
        }

        int number = digits[i] - '2';
        for (char c : characters[number]) {
            x[i] = c;
            build(digits, characters, ans, x, i + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};

        vector<string> ans;
        vector<string> characters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<char> x(digits.size());
        build(digits, characters, ans, x, 0);
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> ans = sol.letterCombinations("23");
    for (string str : ans) {
        cout << str << endl;
    }
}