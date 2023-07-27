#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f(26);
        for (char ch : s)
            f[ch - 'a']++;
        for (char ch : t)
            f[ch - 'a']--;
        for (int i = 0; i < 26; i++)
            if (f[i] > 0)
                return (char)i + 'a';
    }
};