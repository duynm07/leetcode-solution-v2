#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        vector<int> f(2, 0);
        for (int stdnt : students)
            f[stdnt]++;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (f[sandwiches[i]] > 0)
                f[sandwiches[i]]--;
            else
                break;
        }
        return f[0] + f[1];
    }
};