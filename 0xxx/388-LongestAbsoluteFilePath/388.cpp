#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void printStack(stack<pair<int, string>> stack) {
        while (!stack.empty()) {
            cout << stack.top().first << " - " << stack.top().second << " ( " << stack.top().second.length() << " )" << endl;
            stack.pop();
        }
        cout << endl;
    };

    int lengthLongestPath(string input) {
        int currentLength = 0;
        int ans = 1;

        string currentString = "";
        int currentLevel = 0;
        bool isCurrentPathAFile = false;

        stack<pair<int, string>> stack;
        input = input + "\n";

        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];
            if (ch == '\n') {
                while (!stack.empty() && stack.top().first >= currentLevel) {
                    currentLength -= stack.top().second.length() + 1;
                    stack.pop();
                }
                pair<int, string> newString(currentLevel, currentString);
                stack.push(newString);
                currentLength += currentString.length() + 1;
                // cout << currentLength << endl;
                if (isCurrentPathAFile)
                    ans = max(ans, currentLength);
                // printStack(stack);

                currentString = "";
                currentLevel = 0;
                isCurrentPathAFile = false;
            } else if (ch == '\t') {
                currentLevel++;
            } else {
                currentString += ch;
                if (ch == '.') {
                    isCurrentPathAFile = true;
                }
            }
        }

        return ans - 1;
    }
};

int main() {
    Solution solution = Solution();
    // int ans = solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    int ans = solution.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    cout << ans << endl;
}