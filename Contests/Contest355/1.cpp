#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> splitString(const string &inputString, char separator) {
        vector<string> result;
        string item;

        size_t startPos = 0;
        size_t foundPos = inputString.find(separator);

        while (foundPos != string::npos) {
            item = inputString.substr(startPos, foundPos - startPos);
            result.push_back(item);

            startPos = foundPos + 1;
            foundPos = inputString.find(separator, startPos);
        }

        // Push the last substring
        if (startPos < inputString.length()) {
            item = inputString.substr(startPos, inputString.length() - startPos);
            result.push_back(item);
        }

        return result;
    }
    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        vector<string> ans;
        for (string word : words)
        {
            vector<string> splited = splitString(word, separator);
            for (string w : splited) {
                if (!w.empty()) ans.push_back(w);
            }
        }
        
        return ans;
    }
};