#include <vector>
using namespace std;

pair<size_t, size_t> MatrixArgMax(const vector<vector<int>>& matrix) {
    int max = matrix[0][0];
    size_t r = 0, c = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                r = i;
                c = j;
            }
        }
    }
    return make_pair(r, c);
}
