#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const string allVowels = "aoeiuAOEIU";

    string sortVowels(string s) {
        string vowels;
        for (char ch : s)
            if (allVowels.find(ch) != string::npos)
                vowels += ch;

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (allVowels.find(s[i]) != string::npos)
                s[i] = vowels[idx++];
        }

        return s;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}