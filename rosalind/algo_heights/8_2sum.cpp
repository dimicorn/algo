#include <iostream>
#include <algorithm>

using namespace std;

struct elem {
    int val, ind;
};

pair<int, int> two_pointers(elem arr[], int n) {
    int l = 0;
    int r = n-1;
    while (l < n && r >= 0) {
        if (arr[l].val + arr[r].val == 0 && l != r) {
            return make_pair(arr[l].ind, arr[r].ind);
        } else if (arr[l].val + arr[r].val > 0) {
            r--;
        } else {
            l++;
        }
    }
    return make_pair(-1, -1);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    int k, n;
    cin >> k >> n;
    pair<int, int> res[k];
    elem arr[n];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[j].ind = j+1;
            cin >> arr[j].val;
        }
        sort(arr, arr + n, [](const auto& a, const auto& b){return a.val < b.val;});
        res[i] = two_pointers(arr, n);
    }
    for (auto &i : res) {
        if (i.first > i.second) {
            swap(i.first, i.second);
        }

        if (i.first == -1 && i.second == -1) {
            cout << "-1\n";
        } else {
            cout << i.first << ' ' << i.second << '\n';
        }
    }
    return 0;
}
