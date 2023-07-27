#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int nRequest = requests.size();
        int count = 1 << nRequest;
        int ans = 0;

        for (int i = 1; i < count; i++) {
            int nAcceptRequest = 0;
            vector<int> count(n, 0);
            for (int j = 0; j < nRequest; j++) {
                if ((i & (1 << j)) != 0) {
                    nAcceptRequest += 1;
                    count[requests[j][1]]++;
                    count[requests[j][0]]--;
                }
            }
            if (nAcceptRequest <= ans)
                continue;
            bool check = true;
            for (int j = 0; j < n && check; j++)
                if (count[j] != 0)
                    check = false;
            if (check)
                ans = nAcceptRequest;
        }
    }
};