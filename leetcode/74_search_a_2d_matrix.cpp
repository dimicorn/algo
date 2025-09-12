#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int tmp = approxBinSearch(matrix, m, target);
        return binSearch(matrix[tmp], target);
    }   

    int approxBinSearch(const vector<vector<int>>& arr, int rows, int target) {
        int l = 0;
        int r = rows - 1;
        while (l <= r) {
            int m = (r + l) / 2;
            if (arr[m][0] == target)
                return m;
            else if (arr[m][0] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return max(0, r);
    }

    bool binSearch(const vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        if (l == r)
            return arr[l] == target;
        while (l <= r) {
            int m = (r + l) / 2;
            if (arr[m] == target)
                return true;
            else if (arr[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }   
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 3;
    auto sol = new Solution();
    bool res = sol->searchMatrix(matrix, target);
    if (res)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
