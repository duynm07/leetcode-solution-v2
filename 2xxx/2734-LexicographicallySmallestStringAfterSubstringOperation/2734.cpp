#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (i < s.size() && s[i] == 'a')
            i++;

        if (i == s.size())
            return string(s.size() - 1, 'a') + 'z';

        int j = i;
        while (j < s.size() && s[j] != 'a')
            j++;
            
        for (int index = i; index < j; index++) {
            s[index]--;
        }

        return s;
    }
};