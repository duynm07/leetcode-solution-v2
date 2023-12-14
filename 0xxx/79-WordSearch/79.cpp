#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mx = {1, -1, 0, 0};
    vector<int> my = {0, 0, 1, -1};

    bool travel(vector<vector<char>> &board, int x, int y, string word) {
        if (board[x][y] != word[0])
            return false;
        if (word.length() == 1)
            return true;

        queue<pair<int, int>> q;
        vector<vector<int>> free(board.size(), vector<int>(board[0].size(), -1));

        q.push({x, y});
        free[x][y] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ui = u + mx[k];
                int vi = v + my[k];
                if (ui < 0 || ui >= board.size() || vi < 0 || vi >= board[0].size() || free[ui][vi] >= 0)
                    continue;
                if (board[ui][vi] != word[free[u][v] + 1])
                    continue;

                free[ui][vi] = free[u][v] + 1;
                if (free[ui][vi] == word.length() - 1)
                    return true;

                q.push({ui, vi});
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (travel(board, i, j, word))
                    return true;
            }
        }

        return false;
    }
};