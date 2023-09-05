#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minimum2strings(string str1, string str2) {
        if (str1.find(str2) != string::npos)
            return str1;
        if (str2.find(str1) != string::npos)
            return str2;

        int len1 = str1.length();
        int len2 = str2.length();

        // for (int i2 = len2; i2 > 0 && i2 <= len1; i2--) {
        //     string sub2 = str2.substr(0, i2);
        //     string sub1 = str1.substr(len1 - i2, i2);
        //     if (sub1 == sub2) {
        //         str1.append(str2.substr(i2, len2 - i2));
        //         return str1;
        //     }
        // }

        for (int i1 = min(len1, len2); i1 > 0; i1--) {
            string sub1 = str1.substr(len1 - i1, i1);
            string sub2 = str2.substr(0, i1);
            // cout << sub1 << endl;
            if (sub2 == sub1) {
                str1.append(str2.substr(i1, len2 - i1));
                return str1;
            }
        }

        str1.append(str2);
        return str1;
    }

    string minimum3string(string a, string b, string c) {
        string str1 = minimum2strings(minimum2strings(a, b), c);
        string str2 = minimum2strings(a, minimum2strings(b, c));
        if (str1.length() == str2.length()) {
            return str1 < str2 ? str1 : str2;
        }
        return str1.length() < str2.length() ? str1 : str2;
    }
    string minimumString(string a, string b, string c) {
        string ab = minimum2strings(a, b);
        string ba = minimum2strings(b, a);
        string bc = minimum2strings(b, c);
        string cb = minimum2strings(c, b);
        string ac = minimum2strings(a, c);
        string ca = minimum2strings(c, a);

        vector<string> alls;
        string abc = minimum3string(a, b, c);
        string acb = minimum3string(a, c, b);
        string bac = minimum3string(b, a, c);
        string bca = minimum3string(b, c, a);
        string cab = minimum3string(c, a, b);
        string cba = minimum3string(c, b, a);

        alls.push_back(abc);
        alls.push_back(acb);
        alls.push_back(bac);
        alls.push_back(bca);
        alls.push_back(cab);
        alls.push_back(cba);

        int minLength = a.length() + b.length() + c.length() + 1;
        string ans = "";
        for (string str : alls) {
            if (str.length() < minLength || str.length() == minLength && str < ans) {
                minLength = str.length();
                ans = str;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.minimum2strings("abcccccc", "ccdef");
}