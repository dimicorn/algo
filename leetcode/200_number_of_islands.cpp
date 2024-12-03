#include <unordered_set>
#include <deque>
#include <iostream>

using namespace std;

struct pair_hash {
    inline size_t operator()(const pair<int, int> &v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        if (grid.size() == 0)
            return 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1' && visit.find(make_pair(r, c)) == visit.end()) {
                    bfs(grid, r, c);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void bfs(const vector<vector<char> > &grid, const int &r, const int &c) {
        deque<pair<int, int> > q;
        visit.insert(make_pair(r, c));
        q.push_back(make_pair(r, c));
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop_front();
            vector<pair<int, int> > directions = {
                make_pair(1, 0), make_pair(-1, 0),
                make_pair(0, 1), make_pair(0, -1)
            };
            for (const auto &[dr, dc]: directions) {
                int r = row + dr, c = col + dc;
                if (0 <= r && r < rows && 0 <= c && c < cols && 
                grid[r][c] == '1' && visit.find(make_pair(r, c)) == visit.end()) {
                    q.push_back(make_pair(r, c));
                    visit.insert(make_pair(r, c));
                }
            }
        }
    }
private:
    int rows, cols, islands;
    unordered_set<pair<int, int>, pair_hash> visit;
};

int main() {
    vector<vector<char> > grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    Solution* sol = new Solution();
    cout << sol->numIslands(grid) << '\n';
    return 0;
}
