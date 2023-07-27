#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        vector<string> ans;

        for (int i = 0; i < queries.size(); i++) {
            string query = queries[i];
            for (int j = 0; j < dictionary.size(); j++) {
                string dict = dictionary[j];
                int countDiff = 0;
                for (int k = 0; k < query.size(); k++) {
                    if (query[k] != dict[k])
                        countDiff++;
                    if (countDiff > 2)
                        break;
                }
                if (countDiff <= 2) {
                    ans.push_back(query);
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution = Solution();

    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"wood", "joke", "moat"};

    vector<string> ans = solution.twoEditWords(queries, dictionary);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}