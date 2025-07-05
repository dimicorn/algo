#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                checkIfAlive(board, i, j);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                board[i][j] /= 2;
        }
    }
    void checkIfAlive(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        if (i > 0 && j > 0 && board[i-1][j-1] % 2 == 1)
            ++count;
        if (i > 0 && board[i-1][j] % 2 == 1)
            ++count;
        if (i > 0 && j < m - 1 && board[i-1][j+1] % 2 == 1)
            ++count;
        if (i < n - 1 && j > 0 && board[i+1][j-1] % 2 == 1)
            ++count;
        if (i < n - 1 && board[i+1][j] % 2 == 1)
            ++count;
        if (i < n - 1 && j < m - 1 && board[i+1][j+1] % 2 == 1)
            ++count;
        if (j > 0 && board[i][j-1] % 2 == 1)
            ++count;
        if (j < m - 1 && board[i][j+1] % 2 == 1)
            ++count;
        if (board[i][j] % 2 == 1) {
            if (count == 2 || count == 3)
                board[i][j] += 2;
        } else {
            if (count == 3)
                board[i][j] += 2;
        }
    }
private:
    int n;
    int m;
};
