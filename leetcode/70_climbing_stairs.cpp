#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) 
            return 1;
        if (n == 2) 
            return 2;

        int* arr = new int[n];
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; ++i)
            arr[i] = arr[i-1] + arr[i-2];
        int res = arr[n-1];
        delete[] arr;
        return res;
    }
};

int main() {
    int n = 3;
    Solution* sol = new Solution();
    cout << sol->climbStairs(n) << '\n';

    return 0;
}
