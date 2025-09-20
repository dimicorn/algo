#include <bits/stdc++.h>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1(v1), v2(v2) {
        v1_size = v1.size();
        v2_size = v2.size();
    }

    int next() {
        if (first == second && first < v1_size || second == v2_size) {
            ++first;
            return v1[first-1];
        } else {
            ++second;
            return v2[second-1];
        }
    }

    bool hasNext() {
        if (first == v1_size && second == v2_size) {
            return false;
        }
        return true;
    }
private:
    int first = 0;
    int second = 0;
    size_t v1_size;
    size_t v2_size;
    vector<int> v1;
    vector<int> v2;
};

