#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};

        vector<int> ans(2, 1);

        for (int i = 2; i <= rowIndex; i++) {
            cout << "if (rowIndex == " << i << ") return {";
            for (int j = ans.size() - 1; j > 0; j--)
                ans[j] = ans[j] + ans[j - 1];
            ans.push_back(1);
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j];
                if (j < ans.size() - 1)
                    cout << ", ";
            }
            cout << "};" << endl;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> ans = sol.getRow(33);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}