#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26);
        for (char ch : s)
            f[ch]++;

        for (int i = 0; i < s.length(); i++)
            if (f[s[i]] == 1)
                return i;

        return -1;
    }
};

int main() {
    int a = 'a';
    cout << a << endl;
}