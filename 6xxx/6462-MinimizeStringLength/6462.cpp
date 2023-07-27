#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> uniqueChars;

        for (char ch : s) {
            uniqueChars.insert(ch);
        }

        return uniqueChars.size();
    }
};