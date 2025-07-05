#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row = checkRows(board);
        bool col = checkColumns(board);
        bool box = checkBoxes(board);
        return row && col && box;
    }
    bool checkRows(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (seen.find(board[i][j]) != seen.end())
                    return false;
                seen.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkColumns(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;
                if (seen.find(board[j][i]) != seen.end())
                    return false;
                seen.insert(board[j][i]);
            }
        }
        return true;
    }

    bool checkBoxes(vector<vector<char>>& board) {
        for (int i = 1; i < 9; i += 3) {
            for (int j = 1; j < 9; j += 3) {
                unordered_set<char> seen;
                if (board[i][j] != '.')
                    seen.insert(board[i][j]);
                if (board[i-1][j] != '.') {
                    if (seen.find(board[i-1][j]) != seen.end())
                        return false;
                    seen.insert(board[i-1][j]);
                }
                if (board[i+1][j] != '.') {
                    if (seen.find(board[i+1][j]) != seen.end())
                        return false;
                    seen.insert(board[i+1][j]);
                }
                if (board[i][j-1] != '.') {
                    if (seen.find(board[i][j-1]) != seen.end())
                        return false;
                    seen.insert(board[i][j-1]);
                }
                if (board[i-1][j-1] != '.') {
                    if (seen.find(board[i-1][j-1]) != seen.end())
                        return false;
                    seen.insert(board[i-1][j-1]);
                }
                if (board[i+1][j-1] != '.') {
                    if (seen.find(board[i+1][j-1]) != seen.end())
                        return false;
                    seen.insert(board[i+1][j-1]);
                }
                if (board[i][j+1] != '.') {
                    if (seen.find(board[i][j+1]) != seen.end())
                        return false;
                    seen.insert(board[i][j+1]);
                }
                if (board[i-1][j+1] != '.') {
                    if (seen.find(board[i-1][j+1]) != seen.end())
                        return false;
                    seen.insert(board[i-1][j+1]);
                }
                if (board[i+1][j+1] != '.') {
                    if (seen.find(board[i+1][j+1]) != seen.end())
                        return false;
                    seen.insert(board[i+1][j+1]);
                }
            }
        }
        return true;
    }

};
