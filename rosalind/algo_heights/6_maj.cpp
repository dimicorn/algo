#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    int k, n;
    cin >> k >> n;
    int res[k];
    for (int i = 0; i < k; ++i) {
        int a;
        unordered_map<int, int> m;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (m.find(a) == m.end()) {
                m[a] = 1;
            } else {
                m[a]++;
            }
        }
        pair<int, int> max = make_pair(0, 0);
        for (auto &it : m) {
            if (it.second > max.second) {
                max.first = it.first;
                max.second = it.second;
            }
        }
        if (max.second > n/2) {
            res[i] = max.first;
        } else {
            res[i] = -1;
        }
    }

    for (auto &it : res) {
        cout << it << ' ';
    }

    return 0;
}


/*
#include <iostream>
#include <algorithm>

using namespace std;

int maj(int arr[], int n) {
    int count = 1;
    for (int j = 0; j < n - 1; ++j) {
        if (arr[j] == arr[j + 1]) {
            count++;
        } else {
            count = 1;
        }
        if (count > n/2) {
            return arr[j];
        }
    } 
    return -1;
}

int main(int argc, char* argv[]) {
    int a, k, n;
    cin >> k >> n;
    int res[k] = {-1};
    int arr[n];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        sort(arr, arr + n); 
        res[i] = maj(arr, n);
    }
    for (auto &i : res) {
        cout << i << ' ';
    }
    return 0;
}
*/
