#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string stackToString(stack<char> charStack) {
        string result;

        // Pop each character from the stack and append it to the string
        while (!charStack.empty()) {
            result += charStack.top();
            charStack.pop();
        }

        // Reverse the string
        reverse(result.begin(), result.end());

        return result;
    }
    string decodeString(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ']') {
                string encoded_string = "";
                while (st.top() != '[') {
                    char top = st.top();
                    encoded_string = top + encoded_string;
                    st.pop();
                }
                st.pop();

                int k = 0;
                int factor = 1;
                while (!st.empty() && isdigit(st.top())) {
                    int d = st.top() - '0';
                    k = d * factor + k;
                    factor *= 10;
                    st.pop();
                }

                for (int i = 0; i < k; i++) {
                    for (char c : encoded_string) {
                        st.push(c);
                    }
                }
            } else {
                st.push(ch);
            }
        }

        return stackToString(st);
    }
};

int main() {
    Solution sol = Solution();
    string ans = sol.decodeString("3[a]2[bc]");
    cout << ans;
}