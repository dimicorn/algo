#include <vector>

using namespace std;

vector<vector<int>> Transpose(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > t_matrix(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            t_matrix[j][i] = matrix[i][j];
    return t_matrix;
}
