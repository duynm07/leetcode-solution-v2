#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addExtraSpace(vector<string> &words, int width) {
        int numWords = words.size();
        if (numWords == 1) {
            return words[0] + string(width - words[0].length(), ' ');
        }
        int totalLength = 0;
        for (string word : words)
            totalLength += word.length();

        string spaces((width - totalLength) / (numWords - 1), ' ');
        int extraSpace = (width - totalLength) % (numWords - 1);

        string finalString = words[0];
        for (int i = 1; i < words.size(); i++) {
            if (extraSpace) {
                extraSpace--;
                finalString += spaces + " " + words[i];
            } else
                finalString += spaces + words[i];
        }

        return finalString;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<vector<string>> wordGroups;

        vector<string> currWordGroup;
        int currWidth = 0;

        for (string word : words) {
            if (currWidth + word.length() + (currWordGroup.size() > 0) > maxWidth) {
                wordGroups.push_back(currWordGroup);
                currWordGroup.resize(0);
                currWidth = 0;
            }
            currWidth += (currWordGroup.size() > 0) + word.length();
            currWordGroup.push_back(word);
        }

        // wordGroups.push_back(currWordGroup);

        vector<string> ans;
        for (vector<string> wordGroup : wordGroups)
            ans.push_back(addExtraSpace(wordGroup, maxWidth));

        string lastLine = currWordGroup[0];
        for (int i = 1; i < currWordGroup.size(); i++) {
            lastLine += " " + currWordGroup[i];
        }
        lastLine += string(maxWidth - lastLine.length(), ' ');
        ans.push_back(lastLine);

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    sol.fullJustify(words, 16);
}