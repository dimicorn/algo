#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> temp;
        int add = 1;
        int i = n-1;
        while (add == 1 or i >= 0) {
            if (i < 0) {
                temp.push_back(1);
                break;
            }
            digits[i] += add;
            add = digits[i] / 10;
            temp.push_back(digits[i] % 10);
            --i;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
