#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (const auto &num : arr) {
            if (num % 2 == 0 && s.find(num / 2) != s.end())
                return true;
            if (s.find(2 * num) != s.end())
                return true;
            else
                s.insert(num);
        }
        return false;
    }
};
