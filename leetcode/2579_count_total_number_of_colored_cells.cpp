#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long _n = n;
        return 1 + 2 * (_n-1) * _n;
    }
};
