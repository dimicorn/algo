#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        width = static_cast<int>(board.size());
        height = static_cast<int>(board[0].size());
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if ((i == 0 || i == width - 1 || j == 0 || j == height - 1) &&
                    board[i][j] == 'O') {
                    board[i][j] = 'T';
                }
            }
        }
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (board[i][j] == 'T') {
                    dfs(board, i, j, 'T');
                }
            }
        }
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, const int idx, const int jdx, const char t) {
        vector<pair<int, int>> st;
        st.push_back(make_pair(idx, jdx));
        while (!st.empty()) {
            auto [i, j] = st.back();
            st.pop_back();
            if (inBound(i - 1, j) && board[i - 1][j] == 'O') {
                st.push_back(make_pair(i - 1, j));
                board[i - 1][j] = 'T';
            }
            if (inBound(i + 1, j) && board[i + 1][j] == 'O') {
                st.push_back(make_pair(i + 1, j));
                board[i + 1][j] = 'T';
            }
            if (inBound(i, j - 1) && board[i][j - 1] == 'O') {
                st.push_back(make_pair(i, j - 1));
                board[i][j - 1] = 'T';
            }
            if (inBound(i, j + 1) && board[i][j + 1] == 'O') {
                st.push_back(make_pair(i, j + 1));
                board[i][j + 1] = 'T';
            }
        }
    }
    bool inBound(const int i, const int j) {
        return i >= 0 && i < width && j >= 0 && j < height;
    }
    int width;
    int height;
};
